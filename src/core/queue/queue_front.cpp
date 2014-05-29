/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "queue_front.h"

QueueFront::QueueFront()
{
    m_storage = ASharedPointer<QueueStorage>::type(QueueStorage::getStorage());
    for(int i=0; i<QueueFrontManagetAmount; i++)
    {

    }

    //log here
}
