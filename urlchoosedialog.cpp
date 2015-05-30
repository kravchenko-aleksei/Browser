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
    connect(ui->filterEdit, SIGNAL(returnPressed()), this, SLOT(on_applyFilterButton_clicked()));
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


    /*qDebug() << row;
    if (pages.size() > row) {
        Application::navigateTo(pages[row]);
        qDebug() << "Navigating to " << pages[row].getName();
    }*/

    QModelIndex index = model->index(row);
    QString pageNameAndUrl = model->data(index, 2).toString();
    for (auto& page : pages) {
        if (page.getUrl() + " " + page.getName() == pageNameAndUrl) {
            Application::navigateTo(page);
            qDebug() << "Navigating to " << page.getName();
            close();
            return;
        }
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

void UrlChooseDialog::on_applyFilterButton_clicked()
{
    list.clear();
    for (auto& page : pages) {
        if ((page.getUrl() + " " + page.getName()).contains(ui->filterEdit->text())) {
            list.append(page.getUrl() + " " + page.getName());
        }
    }
    model->setStringList(list);
}

void UrlChooseDialog::on_removeFilterButton_clicked()
{
    ui->filterEdit->setText("");
}

void UrlChooseDialog::on_filterEdit_textChanged(const QString &text)
{
    //ignore warning
    text;
    on_applyFilterButton_clicked();
}
