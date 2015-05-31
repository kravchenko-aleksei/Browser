#include "application.h"
#include "bookmarks.h"
#include <QMessageBox>
#include "urlchoosedialog.h"
#include "settingsdialog.h"
#include <QDebug>

StartPage Application::startPage;
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

StartPage &Application::getStartPage()
{
    return startPage;
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

void Application::restoreSession()
{
    if (history.getAll().size() <= 1) {
        navigateTo(WebPageInfo(startPage.get(), nullptr));
        qDebug() << "History is empty, loading default page";
    }
    int reply;
    reply = QMessageBox::question(nullptr, "Session restore", "Restore previous session?"
                                  , QMessageBox::Yes, QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qDebug() << "Restoring session";
        navigateTo(history.getAll()[history.getAll().size() - 2]);
    }
    else {
        qDebug() << "Loading default page";
        navigateTo(WebPageInfo(startPage.get(), nullptr));
    }
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
    w.setValues(history.getMaxPages(), startPage.get());
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



