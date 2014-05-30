/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include <QDebug>

#include "queue_manager.h"

QueueManager::QueueManager() : m_stopThread(false)
{
    storage = QueueStorage::getStorage();
    m_thread = ASharedPointer<AThread>::type(new AThread());
    moveToThread(m_thread.data());
    m_thread->start();

    m_timer.singleShot(EventManagerWaitPeriod, this);

    //log here
}

void QueueManager::manageQueue()
{
    if (m_stopThread)
    {
        //log here
        return;
    }

    //check queuestorage and manage it
    ASharedPointer<IEvent>::type event = ASharedPointer<IEvent>::type(storage->dequeueEvent());
    if (!event.isNull())
    {
        qDebug() << "thread is: " << AThread::currentThreadId();
        //manage event
    }

    m_timer.singleShot(EventManagerWaitPeriod, this);
}

void QueueManager::stop()
{
    m_stopThread = true;
    m_thread->exit();
    m_thread->wait();
}

void QueueManager::callConnected()
{
    manageQueue();
}
