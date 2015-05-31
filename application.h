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
    static void warn(QString message, QWidget *parent);
    static void setMainWindow(MainWindow* _window);
    static void navigateTo(WebPageInfo page);
    static void restoreSession();
    static void viewBookmarks();
    static void viewHistory();
    static void viewSettings();
    static PagesKeeper& getViewedPagesKeeper();
private:
    enum CurrentlyViewedPages {BOOKMARKS, HISTORY};
    static CurrentlyViewedPages currentlyViewedPages;

    static History history;
    static MainWindow* window;
    static BookmarksKeeper bookmarks;
};

#endif // APPLICATION_H
