/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "queue_front.h"

QueueFront::QueueFront()
{
    m_storage = ASharedPointer<QueueStorage>::type(QueueStorage::getStorage());

    //get amount from settings
    int manager_amount = QueueFrontManagetAmount;
    for(int i=0; i<manager_amount; i++)
    {
        m_managers.push_back(ASharedPointer<QueueManager>::type(new QueueManager));
    }

    //init event handler

    //log here
}

QueueFront::~QueueFront()
{}

void QueueFront::pushEvent(IEvent *event)
{
    if (!event)
    {
        //log here
        return;
    }

    m_storage->enqueueEvent(event);
}
