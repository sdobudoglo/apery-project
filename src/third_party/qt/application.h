/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#ifndef APPLICATION_H
#define APPLICATION_H


#include <QApplication>

#include "base_types.h"

class Application
{
public:
    Application(int argc, char * argv[]);
    ~Application();

    int execute();
    AStringList getArguments();

private:
    ASharedPointer<QApplication>::type app;
};

Application::Application(int argc, char * argv[])
{
    app = ASharedPointer<QApplication>::type(new QApplication(argc, argv));
}

Application::~Application()
{
    if (!app.isNull())
        app.clear();
}

int Application::execute()
{
    return app->exec();
}

AStringList Application::getArguments()
{
    return app->arguments();
}


#endif /*APPLICATION_H*/