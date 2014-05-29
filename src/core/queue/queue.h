/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "base_types.h"
#include "queue_storage.h"
#include "queue_manager.h"

class IQueue
{
public:
    virtual static ASharedPointer<IQueue>::type getQueue() = 0;
    virtual void pushEvent(IMessageEvent* event) = 0;

protected:
    IQueue(){}
    virtual ~IQueue(){}

protected:
    ASharedPointer<IQueue>::type m_queue;
};

#endif /*QUEUE_H*/
