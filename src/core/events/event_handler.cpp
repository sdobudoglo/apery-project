/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "event_handler.h"

ASharedPointer<EventHandlerStorage>::type EventHandlerStorage::m_storage;

ASharedPointer<EventHandlerStorage>::type EventHandlerStorage::getHandlerStorage()
{
    if (m_storage.isNull())
    {
        m_storage = ASharedPointer<EventHandlerStorage>::type(new EventHandlerStorage);
    }
    return m_storage;
}

EventHandlerStorage::EventHandlerStorage()
{}

void EventHandlerStorage::declareEventHandler(IEventHandler *handler)
{
    AMutexLocker locker(this);

    if (!m_eventStorage.contains(handler->type().globalType()))
    {
        AMultiMap<EventType::EventIntType, IEventHandler*>::type sub_stor;
        sub_stor.insert(handler->type().type(), handler);
        m_eventStorage.insert(handler->type().globalType(), sub_stor);
    } else
    {
        event_iterator it = m_eventStorage.find(handler->type().globalType());
        it.value().insert(handler->type().type(), handler);
    }
}

void EventHandlerStorage::removeEventHandler(EventType type, IEventHandler *event)
{
    AMutexLocker locker(this);

    event_iterator it = m_eventStorage.find(type.globalType());
    if (it == m_eventStorage.end() ||
            !it.value().contains(type.type()))
    {
        //log here
        return;
    }

    if (event)
        it.value().remove(type.type(), event);
    else
        it.value().remove(type.type());
}

AList<IEventHandler*>::type EventHandlerStorage::getHandlerByType(EventType type)
{
    AMutexLocker locker(this);

    event_iterator it = m_eventStorage.find(type.globalType());
    if (it == m_eventStorage.end())
    {
        //log here
        return AList<IEventHandler*>::type();
    }

    return it.value().values(type.type());
}
