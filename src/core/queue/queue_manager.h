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
#include "timer.h"
#include "connect.h"

class QueueManager : public AObject, public IConnect
{
public:
    QueueManager();

    void stop();
    void manageQueue();
    void callConnected();

private:
    bool m_stopThread;
    ASharedPointer<QueueStorage>::type storage;
    ASharedPointer<AThread>::type m_thread;
    ATimer m_timer;
};

#endif /*QUEUE_MANAGER_H*/
