/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "queue_manager.h"

QueueManager::QueueManager() : m_stopThread(false)
{
    m_eventStorage = QueueStorage::getStorage();
    m_eventHandlerStorage = EventHandlerStorage::getHandlerStorage();

    singleShot(EventManagerWaitPeriod);

    //log here
}

void QueueManager::manage()
{
    if (m_stopThread)
    {
        //log here
        return;
    }

    //check queuestorage and manage it
    ASharedPointer<IEvent>::type event = ASharedPointer<IEvent>::type(m_eventStorage->dequeueEvent());
    if (!event.isNull())
    {
        AList<IEventHandler*>::type handlers = m_eventHandlerStorage->getHandlerByType(event->eventType());
        for (int i=0; i<handlers.size(); i++)
        {
            handlers.at(i)->manageEvent(event);
            //log here
        }
    }

    singleShot(EventManagerWaitPeriod);
}

void QueueManager::stop()
{
    m_stopThread = true;
}
