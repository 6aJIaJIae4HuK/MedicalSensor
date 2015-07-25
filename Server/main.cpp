#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "ReceiveSession.h"
#include "Receiver.h"

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: async_tcp_echo_server <port>\n";
            return 1;
        }

        boost::asio::io_service io_service;

        boost::asio::ip::tcp::tcp::endpoint endpoint(boost::asio::ip::tcp::tcp::v4(), atoi(argv[1]));
        Receiver receiver(io_service, endpoint);
        std::cerr << "RUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUN!\n";
        io_service.run();
        std::cerr << "EXIIIIIIIIIIIIIIIIIIIIIIIIIIIIIT!\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
