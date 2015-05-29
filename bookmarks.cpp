#include "bookmarks.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QDebug>
#include "application.h"
#define BOOKMARKSFILENAME "bookmarks"


BookmarksKeeper::BookmarksKeeper()
{
    QFile file;
    file.setFileName(BOOKMARKSFILENAME);
    bool success = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!success) {
        Application::warn("Error loading bookmarks");
    }
    QTextStream stream(&file);
    while(!stream.atEnd()){
        QString url = stream.readLine();
        QString name = stream.readLine();
        WebPageInfo bookmark(url, name);
        bookmarks.push_back(bookmark);
    }
    qDebug() << "Read " + QString::number(bookmarks.size()) + " bookmarks";
    file.close();
}

void BookmarksKeeper::add(QString url, QString name)
{
    for (auto& bookmark : bookmarks) {
        if (bookmark.getUrl() == url) {
            Application::warn("This bookmark already exists");
            return;
        }
    }
    WebPageInfo info(url, name);
    bookmarks.push_back(info);

    QFile file;
    file.setFileName(BOOKMARKSFILENAME);

    bool success = file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    if (!success) {
        Application::warn("ERROR openning file");
    }
    else {
        qDebug() << "successfully opened file";
    }

    QTextStream stream(&file);
    stream << url << "\n";
    stream << name << "\n";

    file.close();
}

std::vector<WebPageInfo> BookmarksKeeper::getAll()
{
    return bookmarks;
}

