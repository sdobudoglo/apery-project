/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "base_types.h"
#include "application.h"

#include "queue_front.h"
#include "event.h"

int main(int argc, char * argv[])
{
    Application app(argc, argv);

    //FIXME:loader start here

    return app.execute();
}
