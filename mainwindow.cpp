#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bookmarks.h"
#include "application.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->webView, SIGNAL(urlChanged(QUrl)), this, SLOT(updateUrlInBar(QUrl)));
    connect(ui->urlBar, SIGNAL(returnPressed()), this, SLOT(goToUrl()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUrlInBar(QUrl url)
{
    ui->urlBar->setText(url.toString());
}

void MainWindow::goToUrl(QString url)
{
    //If user forgot http:// - stick it on
    if (!(url.startsWith("http://") || url.startsWith("https://"))) {
        url.prepend("http://");
        updateUrlInBar(url);
    }
    ui->webView->setUrl(url);
}

void MainWindow::goToUrl()
{
    QString urlToGoTo = ui->urlBar->text();
    goToUrl(urlToGoTo);
}

void MainWindow::on_actionClear_bookmarks_triggered()
{
    Application::getBookmarks().clear();
}

void MainWindow::on_saveToBookmarksButton_clicked()
{
    Application::getBookmarks().add(WebPageInfo(ui->webView->url().toString(), ui->webView->title()));
}

void MainWindow::on_actionClear_history_triggered()
{
    Application::getHistory().clear();
}

void MainWindow::on_webView_loadFinished(bool success)
{
    if (success) {
        Application::getHistory().add(WebPageInfo(ui->webView->url().toString(), ui->webView->title()));
    }
    ui->progressBar->setVisible(false);
}

void MainWindow::on_refreshButton_clicked()
{
    ui->webView->reload();
}

void MainWindow::on_viewBookmarksButton_clicked()
{
    Application::viewBookmarks();
}

void MainWindow::on_actionBookmarks_triggered()
{
    Application::viewBookmarks();
}

void MainWindow::on_actionHistory_triggered()
{
    Application::viewHistory();
}

void MainWindow::on_actionSettings_triggered()
{
    Application::viewSettings();
}

void MainWindow::on_webView_loadProgress(int progress)
{
    ui->progressBar->setValue(progress);
}

void MainWindow::on_webView_loadStarted()
{
    ui->progressBar->setVisible(true);
}
