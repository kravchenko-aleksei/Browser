#ifndef APPLICATION_H
#define APPLICATION_H
#include "bookmarks.h"
#include "mainwindow.h"


class Application
{
public:
    Application();
    static BookmarksKeeper& getBookmarks();
    static void warn(QString message);
    static void setMainWindow(MainWindow* _window);
private:
    static MainWindow* window;
    static BookmarksKeeper bookmarks;
};

#endif // APPLICATION_H
