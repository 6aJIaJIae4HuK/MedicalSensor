#ifndef SENSORMESSAGEHEADER_H
#define SENSORMESSAGEHEADER_H

#include <boost/cstdint.hpp>


enum class TypeOfMessage : uint8_t { INIT = 0x01,
                                     MEASUREMENT = 0x21,
                                     FINISH = 0x51,
                                     RESPOND_DATA = 0x61,
                                     REQUEST_DATA = 0x81 };

//Somehow remove from global space
uint16_t getLengthOfBody(TypeOfMessage type);

class SensorMessageHeader
{
public:
    static const int kHeaderLength = 4;
    SensorMessageHeader();
    SensorMessageHeader(const SensorMessageHeader& header);
    SensorMessageHeader(const TypeOfMessage);
    ~SensorMessageHeader();

    const char* getData() const;
    char* getData();
    uint16_t getLengthOfMessage() const;
    TypeOfMessage getTypeOfMessage() const;
    void setTypeOfMessage(const TypeOfMessage type);
    bool decodeHeader();
    void encodeHeader();
private:
    uint16_t m_length_of_message;
    TypeOfMessage m_type_of_message;
    uint8_t m_reserved;
    char m_data[kHeaderLength];
};

#endif // SENSORMESSAGEHEADER_H
