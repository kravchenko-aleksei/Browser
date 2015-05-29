#ifndef APPLICATION_H
#define APPLICATION_H
#include "bookmarks.h"
#include "mainwindow.h"
#include "history.h"

class Application
{
public:
    Application();
    static BookmarksKeeper& getBookmarks();
    static History& getHistory();
    static void warn(QString message);
    static void setMainWindow(MainWindow* _window);
private:
    static History history;
    static MainWindow* window;
    static BookmarksKeeper bookmarks;
};

#endif // APPLICATION_H
