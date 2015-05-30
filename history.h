#ifndef HISTORY_H
#define HISTORY_H
#include "webpageinfo.h"
#include "pageskeeper.h"



class History : public PagesKeeper
{
public:
    History();
    virtual void add(WebPageInfo page);
private:
};

#endif // HISTORY_H
