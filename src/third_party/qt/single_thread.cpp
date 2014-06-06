/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "single_thread.h"

ASingleThread::ASingleThread()
{
    moveToThread(&m_thread);
    m_thread.start();
}

ASingleThread::~ASingleThread()
{
    m_thread.exit();
    m_thread.wait();
}

void ASingleThread::singleShot(int msec)
{
    QTimer::singleShot(msec, this, SLOT(singleCall()));
}

void ASingleThread::singleCall()
{
    manage();
}

void ASingleThread::manage()
{
    //log here "It is a virtual slot and must be redifinited"
}
