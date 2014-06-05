/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef QUEUE_FRONT_H
#define QUEUE_FRONT_H

#include "base_types.h"
#include "queue.h"
#include "queue_manager.h"

class QueueFront : public IQueue
{
public:
    QueueFront();
    ~QueueFront();

    void pushEvent(IEvent* event);
    void declareEventHandler(IEventHandler *event_handler);
    void removeEventHandler(EventType type, IEventHandler* event = NULL);

private:
    ASharedPointer<QueueStorage>::type m_storage;
    AList<ASharedPointer<QueueManager>::type>::type m_managers;
    ASharedPointer<EventHandlerStorage>::type m_eventHandlerStorage;
};

#endif /*QUEUE_FRONT_H*/
