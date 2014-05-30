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
    IQueue(){}
    virtual ~IQueue(){}

    virtual void pushEvent(IEvent* event) = 0;
};

#endif /*QUEUE_H*/
