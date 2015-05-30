#include "bookmarks.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QDebug>
#include "application.h"
#define BOOKMARKSFILENAME "bookmarks"


BookmarksKeeper::BookmarksKeeper() : PagesKeeper(BOOKMARKSFILENAME)
{
}



void BookmarksKeeper::add(WebPageInfo page)
{
    for (auto& bookmark : pages) {
        if (bookmark.getUrl() == page.getUrl()) {
            Application::warn("This bookmark already exists");
            return;
        }
    }
    writeToFile(page);
}

