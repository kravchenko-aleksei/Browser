

#ifndef BOOKMARKS_H
#define BOOKMARKS_H
#include <QString>
#include <vector>
#include "webpageinfo.h"

class BookmarksKeeper
{
public:
    BookmarksKeeper();
    void add(QString url, QString name);
    std::vector<WebPageInfo> getAll();
    void clear();
private:
    std::vector<WebPageInfo> bookmarks;
};

#endif // BOOKMARKS_H
