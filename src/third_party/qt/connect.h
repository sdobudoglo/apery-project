/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef CONNECT_H
#define CONNECT_H

#include "base_types.h"

class IConnect
{
public:
    IConnect() {}
    virtual void callConnected() = 0;
};

#endif /*CONNECT_H*/
