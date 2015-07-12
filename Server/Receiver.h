#ifndef RECEIVER_H
#define RECEIVER_H

#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "ReceiveSession.h"

class Receiver
{
public:
    Receiver(boost::asio::io_service& io_service, const boost::asio::ip::tcp::tcp::endpoint& endpoint);

    void startAccept();

    void handleAccept(boost::shared_ptr<ReceiveSession> session, const boost::system::error_code& error);

private:
    boost::asio::io_service& m_io_service;
    boost::asio::ip::tcp::tcp::acceptor m_acceptor;
};

#endif // RECEIVER_H
