/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef MESSAGE_EVENT_H
#define MESSAGE_EVENT_H

#include "base_types.h"
#include "message_types.h"

class IMessageEvent
{
public:
    IMessageEvent(EventType group_type, EventType type, EventTypeSpec::EventPriority priority, AVariant data = 0, bool has_return = false, EventFinishCbk event_cbk = 0);
    virtual ~IMessageEvent();

    AVariant eventResultValue() {return m_resultValue;}
    bool eventHasReturn() { return m_hasReturn; }
    AVariant eventData() { return m_data; }
    EventType eventGlobalType() { return m_groupType; }
    EventType eventType() { return m_type; }
    EventTypeSpec::EventPriority eventPriority() { return m_priority; }

protected:
    EventType m_groupType;
    EventType m_type;

    AVariant m_data;
    bool m_hasReturn;
    EventFinishCbk m_eventCbk;
    AVariant m_resultValue;
    EventTypeSpec::EventPriority m_priority;
};

#endif /*MESSAGE_EVENT_H*/
