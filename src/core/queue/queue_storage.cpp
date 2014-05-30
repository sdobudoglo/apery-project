/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "queue_storage.h"

ASharedPointer<QueueStorage>::type QueueStorage::storage;

QueueStorage::QueueStorage()
{
    //log here
}

ASharedPointer<QueueStorage>::type QueueStorage::getStorage()
{
    if (storage.isNull())
    {
        //log here
        storage = ASharedPointer<QueueStorage>::type(new QueueStorage);
    }

    return storage;
}

void QueueStorage::clear()
{
    if (!storage.isNull())
        storage.clear();
}

IEvent* QueueStorage::dequeueEvent()
{
    AMutexLocker locker(this);

    IEvent* event = 0;
    if (!m_hightQueue.empty())
    {
        event = m_hightQueue.dequeue();
    } else if (!m_middleQueue.empty())
    {
        event = m_middleQueue.dequeue();
    } else if (!m_lowQueue.empty())
    {
        event = m_lowQueue.dequeue();
    }

    return event;
}

void QueueStorage::enqueueEvent(IEvent* event)
{
    AMutexLocker locker(this);

    if (!event)
    {
        //log here
        return;
    }

    switch(event->eventPriority())
    {
    case EventTypeSpec::Hight:
        m_hightQueue.enqueue(event);
        break;
    case EventTypeSpec::Middle:
        m_middleQueue.enqueue(event);
        break;
    case EventTypeSpec::Low:
        m_lowQueue.enqueue(event);
        break;
    default:
        //log here
        ;
    }
}
