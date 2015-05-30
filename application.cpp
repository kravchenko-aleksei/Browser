#include "application.h"
#include "bookmarks.h"
#include <QMessageBox>
#include "urlchoosedialog.h"
#include "settingsdialog.h"

BookmarksKeeper Application::bookmarks;
MainWindow* Application::window;
History Application::history;
Application::CurrentlyViewedPages Application::currentlyViewedPages;



Application::Application()
{

}

BookmarksKeeper &Application::getBookmarks()
{
    return bookmarks;
}

History &Application::getHistory()
{
    return history;
}


void Application::warn(QString message)
{
    QMessageBox::information(window, "WARNING", message, "Ok");
}

void Application::warn(QString message, QWidget* parent)
{
    QMessageBox::information(parent, "WARNING", message, "Ok");
}



void Application::setMainWindow(MainWindow *_window)
{
    window = _window;
}


void Application::navigateTo(WebPageInfo page)
{
    window->goToUrl(page.getUrl());
}

void Application::viewBookmarks()
{
    currentlyViewedPages = BOOKMARKS;
    UrlChooseDialog w;
    w.setModel(bookmarks.getAll());
    w.exec();
}

void Application::viewHistory()
{
    currentlyViewedPages = HISTORY;
    UrlChooseDialog w;
    w.setModel(history.getAll());
    w.exec();
}

void Application::viewSettings()
{
    SettingsDialog w;
    w.setValues(history.getMaxPages());
    w.exec();
}

PagesKeeper& Application::getViewedPagesKeeper()
{
    if (currentlyViewedPages == HISTORY) {
        return history;
    }
    else {
        return bookmarks;
    }
}



