#include <QString>

#ifndef WEBPAGEINFO_H
#define WEBPAGEINFO_H


class WebPageInfo
{
public:
    WebPageInfo(QString url, QString name);
    QString getName();
    QString getUrl();
private:
    QString url;
    QString name;
};

#endif // WEBPAGEINFO_H
