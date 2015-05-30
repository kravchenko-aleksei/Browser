#include "pageskeeper.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "application.h"

PagesKeeper::PagesKeeper(QString _filename) : filename(_filename)
{
    QFile file;
    file.setFileName(filename);
    bool success = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!success) {
        qDebug() << "ERROR LOADING HISTORY";
    }
    QTextStream stream(&file);
    while(!stream.atEnd()){
        QString url = stream.readLine();
        QString name = stream.readLine();
        WebPageInfo page(url, name);
        pages.push_back(page);
    }
    qDebug() << "Read " + QString::number(pages.size()) + " pages";
    file.close();
}

void PagesKeeper::clear()
{
    pages.clear();
    QFile file;
    file.setFileName(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    file.close();
    Application::warn("Cleared");
}

void PagesKeeper::removePage(WebPageInfo page)
{
    for (size_t i = 0; i < pages.size(); ++i) {
        if (pages[i].getUrl() == page.getUrl()) {
            pages.erase(pages.begin() + i);
        }
    }
    rewriteAll();
}

std::vector<WebPageInfo> PagesKeeper::getAll()
{
    return pages;
}

void PagesKeeper::rewriteAll()
{
    QFile file;
    file.setFileName(filename);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream stream(&file);
    for (auto& page : pages) {
        stream << page.getUrl() << "\n";
        stream << page.getName() << "\n";
    }
    file.close();
    qDebug() << "History was updated";
}

void PagesKeeper::writeToFile(WebPageInfo page)
{
    pages.push_back(page);
    QFile file;
    file.setFileName(filename);

    bool success = file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    if (!success) {
        Application::warn("ERROR openning file");
    }
    else {
        qDebug() << "successfully opened file";
    }

    QTextStream stream(&file);
    stream << page.getUrl() << "\n";
    stream << page.getName() << "\n";

    file.close();
}
