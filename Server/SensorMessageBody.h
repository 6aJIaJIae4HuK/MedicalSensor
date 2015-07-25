#ifndef SENSORMESSAGEBODY_H
#define SENSORMESSAGEBODY_H

#include "SensorMessageHeader.h"

class SensorMessageBody
{
public:
    SensorMessageBody();
    SensorMessageBody(const TypeOfMessage type);
    SensorMessageBody(const SensorMessageBody& body);
    ~SensorMessageBody();
    const char* getData() const;
    char* getData();
    uint16_t getLength() const;
    TypeOfMessage getType() const;
    void setType();
private:
    TypeOfMessage m_type_of_msg;
    uint16_t m_length_of_body;
    char* m_data;
};

#endif // SENSORMESSAGEBODY_H
