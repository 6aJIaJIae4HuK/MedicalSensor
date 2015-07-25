#include <cstring>
#include "SensorMessage.h"

SensorMessage::SensorMessage():
    m_header(new SensorMessageHeader()),
    m_body(new SensorMessageBody())
{

}

SensorMessage::SensorMessage(const SensorMessage& message):
    m_header(message.getHeader()),
    m_body(message.getBody())
{

}

SensorMessage::SensorMessage(TypeOfMessage type):
    m_header(new SensorMessageHeader(type)),
    m_body(new SensorMessageBody(type))
{

}

SensorMessage::~SensorMessage()
{
    m_header.reset();
    m_body.reset();
}

const boost::shared_ptr<SensorMessageHeader> SensorMessage::getHeader() const
{
    return boost::shared_ptr<SensorMessageHeader>(m_header);
}

boost::shared_ptr<SensorMessageHeader> SensorMessage::getHeader()
{
    return boost::shared_ptr<SensorMessageHeader>(m_header);
}

const boost::shared_ptr<SensorMessageBody> SensorMessage::getBody() const
{
    return boost::shared_ptr<SensorMessageBody>(m_body);
}

boost::shared_ptr<SensorMessageBody> SensorMessage::getBody()
{
    return boost::shared_ptr<SensorMessageBody>(m_body);
}
