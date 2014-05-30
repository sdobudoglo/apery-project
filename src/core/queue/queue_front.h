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
    QueueFront();
    ~QueueFront();

    void pushEvent(IEvent* event);

private:
    ASharedPointer<QueueStorage>::type m_storage;
    AList<ASharedPointer<QueueManager>::type>::type m_managers;
    //ASharedPointer<QueueEventHandler>::type m_eventHandlerp;
};

#endif /*QUEUE_FRONT_H*/
