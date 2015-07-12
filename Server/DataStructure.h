#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

class DataStructure
{
public:
    static const size_t kHeaderLength = 4;
    static const size_t kMaxBodyLength = 512;

    DataStructure();

    const char* getData() const;

    char* getData();

    const char* getBody() const;

    char* getBody();

    size_t getBodyLength() const;

    void setBodyLength(size_t new_body_length);

    bool decodeHeader();

    void encodeHeader();

private:
    char m_data[kHeaderLength + kMaxBodyLength];
    size_t m_body_length;
};

#endif // DATASTRUCTURE_H
