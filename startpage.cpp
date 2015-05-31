#include "startpage.h"
#include <QFile>
#include <QTextStream>
#define STARTPAGEFILENAME "startpage"
#define DEFAULSTARTPAGE "http://fksis.bsuir.by"


StartPage::StartPage()
{
    QFile file(STARTPAGEFILENAME);
    bool success = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!success) {
        url = DEFAULSTARTPAGE;
        return;
    }
    QTextStream stream(&file);
    url = stream.readLine();
    file.close();
}

QString StartPage::get()
{
    return url;
}

void StartPage::set(QString _url)
{
    url = _url;
    QFile file(STARTPAGEFILENAME);
    bool success = file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    if (!success) {
        return;
    }
    QTextStream stream(&file);
    stream << url;
    file.close();
}

