#ifndef URLCHOOSEDIALOG_H
#define URLCHOOSEDIALOG_H

#include <QDialog>

namespace Ui {
class UrlChooseDialog;
}

class UrlChooseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UrlChooseDialog(QWidget *parent = 0);
    ~UrlChooseDialog();

private:
    Ui::UrlChooseDialog *ui;
};

#endif // URLCHOOSEDIALOG_H
