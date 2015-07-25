#ifndef SENSORMESSAGE_H
#define SENSORMESSAGE_H

#include <boost/shared_ptr.hpp>
#include "SensorMessageHeader.h"
#include "SensorMessageBody.h"

class SensorMessage
{
public:
    SensorMessage();
    SensorMessage(TypeOfMessage type);
    SensorMessage(const SensorMessage& message);
    ~SensorMessage();
    const boost::shared_ptr<SensorMessageHeader> getHeader() const;
    boost::shared_ptr<SensorMessageHeader> getHeader();
    const boost::shared_ptr<SensorMessageBody> getBody() const;
    boost::shared_ptr<SensorMessageBody> getBody();
private:
    boost::shared_ptr<SensorMessageHeader> m_header;
    boost::shared_ptr<SensorMessageBody> m_body;
};

#endif // SENSORMESSAGE_H
