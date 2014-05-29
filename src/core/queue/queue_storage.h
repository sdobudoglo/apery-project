/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef QUEUE_STORAGE_H
#define QUEUE_STORAGE_H

#include "base_types.h"
#include "message_event.h"

class QueueStorage : public AMutex
{
public:
    static ASharedPointer<QueueStorage>::type getStorage();
    static void clear();

    IMessageEvent* dequeueEvent();
    void enqueueEvent(IMessageEvent* event);

private:
    QueueStorage();

    static ASharedPointer<QueueStorage>::type storage;

    AQueue<IMessageEvent*>::type m_hightQueue;
    AQueue<IMessageEvent*>::type m_middleQueue;
    AQueue<IMessageEvent*>::type m_lowQueue;
};

#endif /*QUEUE_STORAGE_H*/
