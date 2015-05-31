#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "application.h"
#define MAXENTRIESVALUE 0xFFFFFFF0



SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::setValues(size_t historyEntries, QString startPage)
{
    ui->maxHistoryEntriesEdit->setText(QString::number(historyEntries));
    ui->startPageEdit->setText(startPage);
}

void SettingsDialog::on_cancelButton_clicked()
{
    close();
}

void SettingsDialog::apply()
{
    QString url = ui->startPageEdit->text();
    Application::getStartPage().set(url);
    size_t entries = ui->maxHistoryEntriesEdit->text().toULong();
    if (entries < 1 || entries > MAXENTRIESVALUE) {
        Application::warn(QString("Invalid value"), this);
        return;
    }
    Application::getHistory().setMaxPages(entries);

}

void SettingsDialog::on_applyButton_clicked()
{
    apply();
}

void SettingsDialog::on_okButton_clicked()
{
    apply();
    close();
}
