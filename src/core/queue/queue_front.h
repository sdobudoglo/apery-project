/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef QUEUE_FRONT_H
#define QUEUE_FRONT_H

#include "base_types.h"
#include "queue.h"

class QueueFront : public IQueue
{
public:
    void pushEvent(IMessageEvent* event);
    static ASharedPointer<IQueue>::type getQueue();

private:
    QueueFront();
    virtual ~QueueFront();
};

#endif /*QUEUE_FRONT_H*/
