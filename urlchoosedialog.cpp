#include "urlchoosedialog.h"
#include "ui_urlchoosedialog.h"
#include <QtCore>
#include "application.h"


UrlChooseDialog::UrlChooseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UrlChooseDialog)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
}

UrlChooseDialog::~UrlChooseDialog()
{
    delete ui;
}

void UrlChooseDialog::setModel(QList<WebPageInfo*> pages)
{
    QListIterator<WebPageInfo*> iter(pages);
    WebPageInfo *info;/* = new WebPageInfo(nullptr, nullptr)*/;
    iter.toFront();
    while(iter.hasNext())
    {
        info  = iter.next();
        list.append(info->getUrl() + " - " + info->getName());
    }
    model->setStringList(list);
    ui->listView->setModel(model);
}

void UrlChooseDialog::setModel(std::vector<WebPageInfo> _pages)
{
    pages = _pages;
    for(auto& page : pages) {
        list.append(page.getUrl() + " " + page.getName());
        qDebug() << "loaded an entry";
    }
    model->setStringList(list);
    ui->listView->setModel(model);
}

void UrlChooseDialog::on_okButton_clicked()
{
    //goToPage();
    int row = ui->listView->currentIndex().row();
    /*QModelIndex index = model->index(row);
    QVariant page = model->data(index, 2).toString(); //получает страницу из модели
    */
    qDebug() << row;
    if (pages.size() > row) {
        Application::navigateTo(pages[row]);
        qDebug() << "Navigating to " << pages[row].getName();
    }

    close();
}

void UrlChooseDialog::on_canceButton_clicked()
{
    close();
}

void UrlChooseDialog::on_deleteButton_clicked()
{
    int row = ui->listView->currentIndex().row();
    Application::getViewedPagesKeeper().removePage(pages[row]);
    pages.erase(pages.begin() + row);
    model->removeRows(ui->listView->currentIndex().row(), 1);
}

void UrlChooseDialog::on_deleteAllButton_clicked()
{
    Application::getViewedPagesKeeper().clear();
}
