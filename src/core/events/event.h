/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef EVENT_H
#define EVENT_H

#include "base_types.h"
#include "event_types.h"

class IEvent
{
public:
    IEvent(EventType type, EventTypeSpec::EventPriority priority, AVariant data = 0, bool has_return = false);
    virtual ~IEvent();

    virtual void finishCbk();

    inline AVariant eventResultValue() {return m_resultValue;}
    inline bool eventHasReturn() { return m_hasReturn; }
    inline AVariant eventData() { return m_data; }
    inline EventType eventType() { return m_type; }
    inline EventTypeSpec::EventPriority eventPriority() { return m_priority; }

protected:
    EventType m_type;
    AVariant m_data;
    bool m_hasReturn;
    AVariant m_resultValue;
    EventTypeSpec::EventPriority m_priority;
};

#endif /*EVENT_H*/
