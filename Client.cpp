//
// Created by Paul Jacobo  on 4/29/20.
//

#include "Client.h"
void Client::readHandler(const boost::system::error_code &ec,
                 std::size_t bytes_transferred)
{
    if (!ec)
    {
        std::cout.write(Client::bytes.data(), bytes_transferred);
        Client::tcp_socket.async_read_some(boost::asio::buffer(bytes), &Client::readHandler);
    }
}

void Client::connectHandler(const boost::system::error_code &ec)
{
    if (!ec)
    {
        std::string r =
                "GET / HTTP/1.1\r\nHost: theboostcpplibraries.com\r\n\r\n";
        write(tcp_socket, boost::asio::buffer(r));
        tcp_socket.async_read_some(boost::asio::buffer(bytes), &Client::readHandler);
    }
}

void Client::resolveHandler(const boost::system::error_code &ec,
                    boost::asio::ip::tcp::resolver::iterator it)
{
    if (!ec)
        tcp_socket.async_connect(*it, &Client::connectHandler);
}

void Client::running(){
    boost::asio::ip::tcp::resolver::query q{"127.0.0.1", "12345"};
    Client::infoMeasure.async_resolve(q,&Client::resolveHandler);
    ioaccess.run();
}

void Client::thread()
{


    boost::thread* thr = new boost::thread(boost::bind(&Client::running, this));

    thr->join();


}

//https://stackoverflow.com/questions/4581476/using-boost-thread-and-a-non-static-class-function