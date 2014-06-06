/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef SINGLE_THREAD_H
#define SINGLE_THREAD_H

#include "base_types.h"

class ASingleThread : public QObject
{
    Q_OBJECT
public:
    ASingleThread();
    virtual ~ASingleThread();

    void singleShot(int msec);

    virtual void manage();

public Q_SLOTS:
    void singleCall();

private:
    QThread m_thread;
};

#endif /*SINGLE_THREAD_H*/
