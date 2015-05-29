#include "history.h"
#include <QFile>
#include <algorithm>
#include <QTextStream>
#include <vector>
#include "application.h"
#include <QDebug>
#define HISTORYFILENAME "history"

History::History()
{
    QFile file;
    file.setFileName(HISTORYFILENAME);
    bool success = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!success) {
        qDebug() << "ERROR LOADING HISTORY";
    }
    QTextStream stream(&file);
    while(!stream.atEnd()){
        QString url = stream.readLine();
        QString name = stream.readLine();
        WebPageInfo bookmark(url, name);
        visitedPages.push_back(bookmark);
    }
    qDebug() << "Read " + QString::number(visitedPages.size()) + " visited pages";
    file.close();
}

void History::add(WebPageInfo page)
{
    /*for (auto& it = visitedPages.begin(); it != visitedPages.end(); ++it) {
        if (it->getUrl() == page.getUrl()) {
            //update
            visitedPages.push_back(page);
            visitedPages.erase(it);
            rewriteAll();
            return;
        }
    }*/
    for (size_t i = 0; i < visitedPages.size(); ++i) {
        if (visitedPages[i].getUrl() == page.getUrl()) {
            visitedPages.push_back(page);
            visitedPages.erase(visitedPages.begin() + i);
            rewriteAll();
            return;
        }
    }

    visitedPages.push_back(page);

    QFile file;
    file.setFileName(HISTORYFILENAME);

    bool success = file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    if (!success) {
        Application::warn("ERROR openning file");
    }
    else {
        qDebug() << "successfully opened file";
    }

    QTextStream stream(&file);
    stream << page.getUrl() << "\n";
    stream << page.getName() << "\n";

    file.close();
}


void History::clear()
{
    visitedPages.clear();
    QFile file;
    file.setFileName(HISTORYFILENAME);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    file.close();
    Application::warn("History cleared");
}

void History::rewriteAll()
{
    QFile file;
    file.setFileName(HISTORYFILENAME);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream stream(&file);
    for (auto& page : visitedPages) {
        stream << page.getUrl() << "\n";
        stream << page.getName() << "\n";
    }
    file.close();
    qDebug() << "History was updated";
}
