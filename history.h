#ifndef HISTORY_H
#define HISTORY_H
#include "webpageinfo.h"
#include <vector>


class History
{
public:
    History();
    void add(WebPageInfo page);
    void clear();
private:
    void rewriteAll();
    std::vector<WebPageInfo> visitedPages;
};

#endif // HISTORY_H
