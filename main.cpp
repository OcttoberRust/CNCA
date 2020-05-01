#include <iostream>
#include <string>
#include <boost/version.hpp>
#include <iostream>
#include "Server.h"
#include "Message.h"
#include "Client.h"
#include <boost/thread.hpp>
#include <boost/chrono.hpp>


int main()
{
    Client client = Client("127.0.0.1", 12345);

    client.thread();

    //https://stackoverflow.com/questions/7448956/invoking-a-function-from-another-class-with-boost-in-c
    return 0;
}