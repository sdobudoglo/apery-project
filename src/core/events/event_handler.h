/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "base_types.h"
#include "event.h"

class IEventHandler
{
public:
    IEventHandler(EventType type) : m_type(type) {}
    virtual ~IEventHandler() {}

    virtual void manageEvent(ASharedPointer<IEvent>::type event) = 0;

    inline EventType type() { return m_type; }

protected:
    EventType m_type;
};

class EventHandlerStorage : public AMutex
{
public:
    static ASharedPointer<EventHandlerStorage>::type getHandlerStorage();

    void declareEventHandler(IEventHandler* handler);
    void removeEventHandler(EventType type, IEventHandler* event = NULL);
    AList<IEventHandler*>::type getHandlerByType(EventType type);

private:
    EventHandlerStorage();

private:
    AMap<EventType::EventIntType, AMultiMap<EventType::EventIntType, IEventHandler*>::type>::type m_eventStorage;
    typedef AMap<EventType::EventIntType, AMultiMap<EventType::EventIntType, IEventHandler*>::type>::type::iterator event_iterator;
    static ASharedPointer<EventHandlerStorage>::type m_storage;
};

#endif /*EVENT_HANDLER_H*/
