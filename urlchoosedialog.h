#ifndef URLCHOOSEDIALOG_H
#define URLCHOOSEDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include "webpageinfo.h"
#include <vector>



namespace Ui {
class UrlChooseDialog;
}

class UrlChooseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit UrlChooseDialog(QWidget *parent = 0);
    ~UrlChooseDialog();
    void setModel(QList<WebPageInfo*> pages);
    void setModel(std::vector<WebPageInfo> pages);
private slots:
    void on_okButton_clicked();

    void on_canceButton_clicked();

    void on_deleteButton_clicked();

    void on_deleteAllButton_clicked();

    void on_applyFilterButton_clicked();

    void on_removeFilterButton_clicked();

    void on_filterEdit_textChanged(const QString &arg1);

private:
    std::vector<WebPageInfo> pages;
    Ui::UrlChooseDialog *ui;
    QStringListModel *model;
    QList<QString> list;
};

#endif // URLCHOOSEDIALOG_H
