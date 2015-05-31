#ifndef STARTPAGE_H
#define STARTPAGE_H
#include <QString>



class StartPage
{
public:
    StartPage();
    QString get();
    void set(QString _url);
private:
    QString url;
};

#endif // STARTPAGE_H
