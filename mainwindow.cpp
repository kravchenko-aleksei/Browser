#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui->urlBar->setText( url.toString() );
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

