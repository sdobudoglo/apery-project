/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "queue_manager.h"

QueueManager::QueueManager() : m_stopThread(false)
{
    //log here
    storage = QueueStorage::getStorage();
    m_thread = ASharedPointer<AThread>::type(new AThread());
    moveToThread(m_thread.data());
}

void QueueManager::manageQueue()
{
    if (m_stopThread)
    {
        //log here
        return;
    }

    //check queuestorage and manage it
    ASharedPointer<IMessageEvent>::type event = ASharedPointer<IMessageEvent>::type(storage->dequeueEvent());
    if (!event.isNull())
    {
        ;//manage event
    }

    ATimer::singleShot(EventManagerWaitPeriod, this, CONNECTED_METHOD(manageQueue));
}

void QueueManager::start()
{
    ATimer::singleShot(EventManagerWaitPeriod, this, CONNECTED_METHOD(manageQueue));
}

void QueueManager::stop()
{
    m_stopThread = true;
    m_thread->exit();
    m_thread->wait();
}
