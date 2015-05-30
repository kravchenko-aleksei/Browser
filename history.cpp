#include "history.h"
#include <QFile>
#include <algorithm>
#include <QTextStream>
#include <vector>
#include "application.h"
#include <QDebug>
#define HISTORYFILENAME "history"

History::History() : PagesKeeper(HISTORYFILENAME)
{
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

    PagesKeeper::writeToFile(page);
}

