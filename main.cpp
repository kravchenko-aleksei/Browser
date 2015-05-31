#include <QApplication>
#include "mainwindow.h"
#include "application.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Application::setMainWindow(&w);
    Application::restoreSession();
    w.show();
    
    return a.exec();
}
