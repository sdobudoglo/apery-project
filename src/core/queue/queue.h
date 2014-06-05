/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "base_types.h"
#include "queue_storage.h"
#include "event_handler.h"

class IQueue
{
public:
    IQueue(){}
    virtual ~IQueue(){}

    virtual void pushEvent(IEvent* event) = 0;
    virtual void declareEventHandler(IEventHandler* event_handler) = 0;
    virtual void removeEventHandler(EventType type, IEventHandler* event = NULL) = 0;
};

#endif /*QUEUE_H*/
