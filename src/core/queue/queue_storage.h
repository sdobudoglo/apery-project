/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef QUEUE_STORAGE_H
#define QUEUE_STORAGE_H

#include "base_types.h"
#include "message_event.h"

class QueueStorage
{
public:
    static ASharedPointer<QueueStorage>::type getStorage();

    virtual IMessageEvent dequeueEvent();
    virtual void enqueueEvent(IMessageEvent event);

private:
    QueueStorage(){}
    ~QueueStorage(){}

    static ASharedPointer<QueueStorage>::type storage;

    AQueue<IMessageEvent> m_hightQueue;
    AQueue<IMessageEvent> m_middleQueue;
    AQueue<IMessageEvent> m_lowQueue;
};

#endif /*QUEUE_STORAGE_H*/
