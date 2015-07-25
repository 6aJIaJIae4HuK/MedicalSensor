#include "SensorMessageBody.h"

SensorMessageBody::SensorMessageBody()
{

}

SensorMessageBody::SensorMessageBody(const TypeOfMessage type)
{
    m_length_of_body = getLengthOfBody(type);
    m_data = new char[m_length_of_body];
}

SensorMessageBody::SensorMessageBody(const SensorMessageBody& body) :
    m_type_of_msg(body.getType()),
    m_length_of_body(body.getLength())
{
    m_data = new char[m_length_of_body];
}

SensorMessageBody::~SensorMessageBody()
{
    delete[] m_data;
}

const char* SensorMessageBody::getData() const
{
    return m_data;
}

char* SensorMessageBody::getData()
{
    return m_data;
}

uint16_t SensorMessageBody::getLength() const
{
    return m_length_of_body;
}

TypeOfMessage SensorMessageBody::getType() const
{
    return m_type_of_msg;
}

