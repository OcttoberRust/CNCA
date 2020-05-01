#include <string>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <array>
#include <string>
#include <iostream>


#ifndef CNCA_CLIENT_H
#define CNCA_CLIENT_H

//https://theboostcpplibraries.com/boost.asio-network-programming
class Client {
private:
    std::string cHost;
    int cPort;
    boost::asio::io_service ioaccess; //ioservice
    boost::asio::ip::tcp::resolver infoMeasure{ioaccess}; // resolve
    boost::asio::ip::tcp::socket tcp_socket{ioaccess};
    std::array<char, 4096> bytes;

public:
    Client(std::string host, int port){
        cHost = host;
        cPort = port;
    }

    void readHandler(const boost::system::error_code &ec,
                      std::size_t bytes_transferred);

    void connectHandler(const boost::system::error_code &ec);

    void resolveHandler(const boost::system::error_code &ec,
                         boost::asio::ip::tcp::resolver::iterator it);

    void running();

    void thread();



};
//https://stackoverflow.com/questions/4581476/using-boost-thread-and-a-non-static-class-function



#endif //CNCA_CLIENT_H
