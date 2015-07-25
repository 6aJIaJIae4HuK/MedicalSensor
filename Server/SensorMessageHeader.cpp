#include <string.h>
#include "SensorMessageHeader.h"

SensorMessageHeader::SensorMessageHeader()
{

}

SensorMessageHeader::SensorMessageHeader(const SensorMessageHeader& header) :
    m_length_of_message(header.getLengthOfMessage()),
    m_type_of_message(header.getTypeOfMessage())
{
    memcpy(m_data, header.getData(), kHeaderLength);
}

SensorMessageHeader::SensorMessageHeader(const TypeOfMessage type) :
    m_type_of_message(type),
    m_length_of_message(getLengthOfBody(type) + kHeaderLength)
{

}

SensorMessageHeader::~SensorMessageHeader()
{

}

const char* SensorMessageHeader::getData() const
{
    return m_data;
}

char* SensorMessageHeader::getData()
{
    return m_data;
}

uint16_t SensorMessageHeader::getLengthOfMessage() const
{
    return m_length_of_message;
}

bool SensorMessageHeader::decodeHeader()
{
    memcpy(&m_length_of_message, m_data + 0, 2);
    memcpy(&m_type_of_message, m_data + 2, 1);
    memcpy(&m_reserved, m_data + 3, 1);
    return (getLengthOfBody(m_type_of_message) == kHeaderLength + m_length_of_message);
}

void SensorMessageHeader::encodeHeader()
{
    memcpy(m_data + 0, &m_length_of_message, 2);
    memcpy(m_data + 2, &m_type_of_message, 1);
    memcpy(m_data + 3, &m_reserved, 1);
}

TypeOfMessage SensorMessageHeader::getTypeOfMessage() const
{
    return m_type_of_message;
}

void SensorMessageHeader::setTypeOfMessage(const TypeOfMessage type)
{
    m_type_of_message = type;
    m_length_of_message = getLengthOfBody(type) + kHeaderLength;
    encodeHeader();
}

uint16_t getLengthOfBody(TypeOfMessage type)
{
    switch (type)
    {
        case TypeOfMessage::INIT:
            return 10;
        case TypeOfMessage::MEASUREMENT:
            return 27;
        case TypeOfMessage::FINISH:
            return 0;
        case TypeOfMessage::REQUEST_DATA:
            return 0;
        case TypeOfMessage::RESPOND_DATA:
            return 0;
    }
    return 0;
}
