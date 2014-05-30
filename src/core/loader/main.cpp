/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "base_types.h"
#include "application.h"

#include "queue_front.h"
#include "event.h"

#include <QDebug>

int main(int argc, char * argv[])
{
    Application app(argc, argv);

    ASharedPointer<IQueue>::type queue = ASharedPointer<QueueFront>::type(new QueueFront);
    qDebug() << "main thread id: " << AThread::currentThreadId();
    AList<IEvent*>::type event_list;
    for (int i=0; i<10; i++)
    {
        IEvent* event = new IEvent(EventTypeSpec::DBEvent, EventTypeSpec::ExecuteRequestEvent, EventTypeSpec::Hight);
        event_list.push_back(event);
        queue->pushEvent(event);
    }

    return app.execute();
}
