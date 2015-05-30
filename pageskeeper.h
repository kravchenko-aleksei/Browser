#ifndef PAGESKEEPER_H
#define PAGESKEEPER_H
#include <vector>
#include "webpageinfo.h"

class PagesKeeper
{
public:
    PagesKeeper(QString _filename);
    virtual void add(WebPageInfo page) = 0;
    void clear();
    void removePage(WebPageInfo page);
    std::vector<WebPageInfo> getAll();
protected:
    void rewriteAll();
    void writeToFile(WebPageInfo info);
    QString filename;
    std::vector<WebPageInfo> pages;
};

#endif // PAGESKEEPER_H
