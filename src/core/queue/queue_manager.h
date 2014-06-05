/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef QUEUE_MANAGER_H
#define QUEUE_MANAGER_H

#include "base_types.h"
#include "event_types.h"
#include "queue_storage.h"
#include "constants.h"
#include "single_thread.h"
#include "event_handler.h"
#include "queue.h"
#include "event_handler.h"

class QueueManager : public ASingleThread
{
public:
    QueueManager();

    void manage();
    void stop();

private:
    bool m_stopThread;
    ASharedPointer<QueueStorage>::type m_eventStorage;
    ASharedPointer<EventHandlerStorage>::type m_eventHandlerStorage;
};

#endif /*QUEUE_MANAGER_H*/
