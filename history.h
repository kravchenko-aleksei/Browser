#ifndef HISTORY_H
#define HISTORY_H
#include "webpageinfo.h"
#include "pageskeeper.h"



class History : public PagesKeeper
{
public:
    History();
    size_t getMaxPages();
    void setMaxPages(size_t pages);
    virtual void add(WebPageInfo page);
private:
    size_t maxKeptPages;
};

#endif // HISTORY_H
