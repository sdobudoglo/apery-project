/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef TIMER_H
#define TIMER_H

#include "base_types.h"
#include "connect.h"

class ATimer : public QObject
{
    Q_OBJECT
public:
    ATimer();
    virtual ~ATimer();

    void singleShot(const int msec, IConnect* slot_obj);

public Q_SLOTS:
    void singleCall();

private:
    IConnect* m_slotObj;

};

#endif /*TIMER_H*/
