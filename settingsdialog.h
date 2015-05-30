#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();
    void setValues(size_t historyEntries);
private slots:
    void on_cancelButton_clicked();

    void on_applyButton_clicked();

    void on_okButton_clicked();

private:
    void apply();
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
