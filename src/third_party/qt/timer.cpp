/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "timer.h"

ATimer::ATimer()
{}

ATimer::~ATimer()
{}

void ATimer::singleShot(const int msec, IConnect* slot_obj)
{
    if (!slot_obj)
    {
        //log here
        return;
    }
    m_slotObj = slot_obj;

    QTimer::singleShot(msec, this, SLOT(singleCall()));
}

void ATimer::singleCall()
{
    m_slotObj->callConnected();
}
