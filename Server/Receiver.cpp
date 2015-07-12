#include "Receiver.h"

using boost::asio::ip::tcp;

Receiver::Receiver(boost::asio::io_service& io_service,
                   const tcp::endpoint& endpoint) : m_io_service(io_service),
                                                    m_acceptor(io_service, endpoint)
{
    startAccept();
}

void Receiver::startAccept()
{
    boost::shared_ptr<ReceiveSession> new_session(new ReceiveSession(m_io_service));
    m_acceptor.async_accept(new_session->getSocket(),
                            boost::bind(&Receiver::handleAccept, this,
                                        new_session, boost::asio::placeholders::error));
}

void Receiver::handleAccept(boost::shared_ptr<ReceiveSession> session, const boost::system::error_code& error)
{
    if (!error)
    {
        session->start();
    }
    startAccept();
}
