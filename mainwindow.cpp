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
    ui->webView->setUrl(url);
    updateUrlInBar(url);
}

void MainWindow::goToUrl()
{
    QString urlToGoTo = ui->urlBar->text();

    //If user forgot http:// - stick it on
    if (! (urlToGoTo.startsWith("http://") || urlToGoTo.startsWith("https://")) )
    {
        urlToGoTo.prepend("http://");
        ui->urlBar->setText( urlToGoTo );
    }

    ui->webView->setUrl( urlToGoTo );
}

void MainWindow::on_actionClear_bookmarks_triggered()
{
    Application::getBookmarks().clear();
}

void MainWindow::on_saveToBookmarksButton_clicked()
{
    Application::getBookmarks().add({ui->webView->url().toString(), ui->webView->title()});
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
