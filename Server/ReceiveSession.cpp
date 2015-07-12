#include "ReceiveSession.h"

using boost::asio::ip::tcp;

ReceiveSession::ReceiveSession(boost::asio::io_service& io_service) : m_socket(io_service)
{
}

tcp::socket& ReceiveSession::getSocket()
{
    return m_socket;
}

void ReceiveSession::start()
{
    boost::asio::async_read(m_socket,
                            boost::asio::buffer(m_msg_to_read.getData(), DataStructure::kHeaderLength),
                            boost::bind(&ReceiveSession::handleReadHeader, shared_from_this(),
                                        boost::asio::placeholders::error()));
}

void ReceiveSession::handleReadHeader(const boost::system::error_code& error)
{
    if (!error && m_msg_to_read.decodeHeader())
    {
        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_msg_to_read.getBody(), m_msg_to_read.getBodyLength()),
                                boost::bind(&ReceiveSession::handleReadBody, shared_from_this(),
                                            boost::asio::placeholders::error));
    }
}

void ReceiveSession::handleReadBody(const boost::system::error_code& error)
{
    if (!error)
    {
        //Here a pushing to some queue of messages
        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_msg_to_read.getData(), DataStructure::kHeaderLength),
                                boost::bind(&ReceiveSession::handleReadHeader, shared_from_this(),
                                            boost::asio::placeholders::error));
    }
}
