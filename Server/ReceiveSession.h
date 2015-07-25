#ifndef RECEIVESESSION_H
#define RECEIVESESSION_H

#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/lockfree/spsc_queue.hpp>

#include "SensorMessage.h"

class ReceiveSession : public boost::enable_shared_from_this<ReceiveSession>
{
public:
    ReceiveSession(boost::asio::io_service& io_service);

    boost::asio::ip::tcp::tcp::socket& getSocket();

    void start();

    void handleReadHeader(const boost::system::error_code& error);

    void handleReadBody(const boost::system::error_code& error);

private:
    boost::asio::ip::tcp::tcp::socket m_socket;
    SensorMessage m_msg_to_read;
    boost::shared_ptr<boost::lockfree::spsc_queue<SensorMessage, boost::lockfree::capacity<1024> > > m_queue_of_messages;
};

#endif // RECEIVESESSION_H
