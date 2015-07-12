#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "DataStructure.h"

DataStructure::DataStructure() : m_body_length(0)
{

}

const char* DataStructure::getData() const
{
    return m_data;
}

char* DataStructure::getData()
{
    return m_data;
}

const char* DataStructure::getBody() const
{
    return m_data + kHeaderLength;
}

char* DataStructure::getBody()
{
    return m_data + kHeaderLength;
}

size_t DataStructure::getBodyLength() const
{
    return m_body_length;
}

void DataStructure::setBodyLength(size_t new_body_length)
{
    m_body_length = new_body_length;
    if (m_body_length > kMaxBodyLength)
        m_body_length = kMaxBodyLength;
}

bool DataStructure::decodeHeader()
{
    char header[kHeaderLength + 1] = "";
    std::strncat(header, m_data, kHeaderLength);
    m_body_length = atoi(header);
    if (m_body_length > kMaxBodyLength)
    {
        m_body_length = 0;
        return false;
    }
    return true;
}

void DataStructure::encodeHeader()
{
    char header[kHeaderLength + 1] = "";
    sprintf(header, "%4d", m_body_length);
    memcpy(m_data, header, kHeaderLength);
}
