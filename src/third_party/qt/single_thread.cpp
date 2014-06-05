/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "single_thread.h"

ASingleThread::ASingleThread()
{}

ASingleThread::~ASingleThread()
{
    m_thread.exit();
    m_thread.wait();
}

void ASingleThread::moveThisToThread()
{
    moveToThread(&m_thread);
    m_thread.start();
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
