/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef QUEUE_MANAGER_H
#define QUEUE_MANAGER_H

#include "base_types.h"
#include "message_types.h"
#include "queue_storage.h"
#include "constants.h"

class QueueManager : public AObject
{
public:
    QueueManager();

    void start();
    void stop();

private CONNECTED_METHODS:
    void manageQueue();

private:
    bool m_stopThread;
    ASharedPointer<QueueStorage>::type storage;
    ASharedPointer<AThread>::type m_thread;
};

#endif /*QUEUE_MANAGER_H*/
