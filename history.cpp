#include "history.h"
#include <QFile>
#include <algorithm>
#include <QTextStream>
#include <vector>
#include "application.h"
#include <QDebug>
#define HISTORYFILENAME "history"
#define HISTORYSETTINGSFILENAME "historysettings"
#define MAXKEPTPAGES_DEFAULT_VALUE 100


History::History() : PagesKeeper(HISTORYFILENAME)
{
    QFile file(HISTORYSETTINGSFILENAME);
    bool success = file.open(QIODevice::ReadOnly);
    if (!success) {
        qDebug() << "No history settings file";
        maxKeptPages = MAXKEPTPAGES_DEFAULT_VALUE;
    }
    file.read((char*)&maxKeptPages, sizeof maxKeptPages);
    file.close();
}

size_t History::getMaxPages()
{
    return maxKeptPages;
}

void History::setMaxPages(size_t _maxKeptPages)
{
    if (maxKeptPages == _maxKeptPages) {
        return;
    }
    maxKeptPages = _maxKeptPages;
    if (pages.size() >= maxKeptPages){
        while(pages.size() > maxKeptPages) {
            pages.erase(pages.begin());
        }
        rewriteAll();
    }
    QFile file(HISTORYSETTINGSFILENAME);
    bool success = file.open(QIODevice::Truncate | QIODevice::WriteOnly);
    if (!success) {
        qDebug() << "Erorr openning history settings file";
    }
    file.write((const char*)&maxKeptPages, sizeof maxKeptPages);
    file.close();
}

void History::add(WebPageInfo page)
{
    for (size_t i = 0; i < pages.size(); ++i) {
        if (pages[i].getUrl() == page.getUrl()) {
            pages.push_back(page);
            pages.erase(pages.begin() + i);
            rewriteAll();
            return;
        }
    }
    if (pages.size() >= maxKeptPages) {
        while(pages.size() > maxKeptPages) {
            pages.erase(pages.begin());
        }
        rewriteAll();
    }

    PagesKeeper::writeToFile(page);
}

