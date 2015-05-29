#include "webpageinfo.h"

WebPageInfo::WebPageInfo(QString _url, QString _name) : url(_url), name(_name)
{

}

QString WebPageInfo::getName()
{
    return name;
}

QString WebPageInfo::getUrl()
{
    return url;
}

