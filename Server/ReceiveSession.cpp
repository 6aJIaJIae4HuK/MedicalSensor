#include "ReceiveSession.h"

using boost::asio::ip::tcp;

ReceiveSession::ReceiveSession(boost::asio::io_service& io_service) :
    m_socket(io_service),
    m_queue_of_messages(new boost::lockfree::spsc_queue<SensorMessage, boost::lockfree::capacity<1024> >)
{
}

tcp::socket& ReceiveSession::getSocket()
{
    return m_socket;
}

void ReceiveSession::start()
{
    boost::asio::async_read(m_socket,
                            boost::asio::buffer(m_msg_to_read.getHeader()->getData(), SensorMessageHeader::kHeaderLength),
                            boost::bind(&ReceiveSession::handleReadHeader, shared_from_this(),
                                        boost::asio::placeholders::error()));
}

void ReceiveSession::handleReadHeader(const boost::system::error_code& error)
{
    if (!error && m_msg_to_read.getHeader()->decodeHeader())
    {
        if (m_msg_to_read.getHeader()->getTypeOfMessage() == TypeOfMessage::MEASUREMENT)
            m_queue_of_messages->push(m_msg_to_read);
        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_msg_to_read.getBody()->getData(), m_msg_to_read.getBody()->getLength()),
                                boost::bind(&ReceiveSession::handleReadBody, shared_from_this(),
                                            boost::asio::placeholders::error));
    }
}

void ReceiveSession::handleReadBody(const boost::system::error_code& error)
{
    if (!error)
    {
        //Here a pushing to some queue of messages
        m_queue_of_messages->push(m_msg_to_read);
        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_msg_to_read.getHeader()->getData(), SensorMessageHeader::kHeaderLength),
                                boost::bind(&ReceiveSession::handleReadHeader, shared_from_this(),
                                            boost::asio::placeholders::error));
    }
}
