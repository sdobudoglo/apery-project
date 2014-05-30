/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef EVENT_TYPES_H
#define EVENT_TYPES_H

struct EventTypeSpec
{
    enum EventPriority
    {
        Hight = 0,
        Middle,
        Low
    };

    enum GlobalEventType
    {
        DBEvent = 0,
        UIEvent
    };

    enum DBEventType
    {
        GetDataEvent = 0,
        SetDataEvent,
        ExecuteRequestEvent
    };

    enum UIEventType
    {
        UnlockStartScreenEvent = 0
    };

};
#endif /*EVENT_TYPES_H*/
