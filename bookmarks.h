

#ifndef BOOKMARKS_H
#define BOOKMARKS_H
#include <QString>
#include "pageskeeper.h"


class BookmarksKeeper : public PagesKeeper
{
public:
    BookmarksKeeper();
    virtual void add(WebPageInfo page);
private:
};

#endif // BOOKMARKS_H
