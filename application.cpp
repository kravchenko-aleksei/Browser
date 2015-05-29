#include "application.h"
#include "bookmarks.h"
#include <QMessageBox>


BookmarksKeeper Application::bookmarks;
MainWindow* Application::window;

Application::Application()
{

}

BookmarksKeeper &Application::getBookmarks()
{
    return bookmarks;
}


void Application::warn(QString message)
{
    QMessageBox::information(window, "WARNING", message, "Ok");
}



void Application::setMainWindow(MainWindow *_window)
{
    window = _window;
}


