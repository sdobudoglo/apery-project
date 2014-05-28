/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "base_types.h"
#include "queue_storage.h"

class IQueue
{
public:
    IQueue(){}
    virtual ~IQueue(){}

    virtual void pushEventMsg() = 0;

protected:
    //AList<QueueManager>::type m_managerList;
    //ASharedPointer<HandleMapper>::type m_handleMapper;
    //ASharedPointer<QueueStorage>::type m_queue;
};

#endif /*QUEUE_H*/
