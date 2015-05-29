#include "urlchoosedialog.h"
#include "ui_urlchoosedialog.h"

UrlChooseDialog::UrlChooseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UrlChooseDialog)
{
    ui->setupUi(this);
}

UrlChooseDialog::~UrlChooseDialog()
{
    delete ui;
}
