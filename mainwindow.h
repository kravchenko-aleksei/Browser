
#include <QMainWindow>
#include <QUrl>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void goToUrl(QString url);
    ~MainWindow();

private slots:
    void updateUrlInBar(QUrl);

    void goToUrl();

    void on_actionClear_bookmarks_triggered();

    void on_saveToBookmarksButton_clicked();

    void on_actionClear_history_triggered();

    void on_webView_loadFinished(bool arg1);

    void on_refreshButton_clicked();

    void on_viewBookmarksButton_clicked();

    void on_actionBookmarks_triggered();

    void on_actionHistory_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
