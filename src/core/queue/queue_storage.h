/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef QUEUE_STORAGE_H
#define QUEUE_STORAGE_H

#include "base_types.h"
#include "event.h"

class QueueStorage : public AMutex
{
public:
    static ASharedPointer<QueueStorage>::type getStorage();
    static void clear();

    IEvent* dequeueEvent();
    void enqueueEvent(IEvent* event);

private:
    QueueStorage();

    static ASharedPointer<QueueStorage>::type storage;

    AQueue<IEvent*>::type m_hightQueue;
    AQueue<IEvent*>::type m_middleQueue;
    AQueue<IEvent*>::type m_lowQueue;
};

#endif /*QUEUE_STORAGE_H*/
