
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
    ~MainWindow();

private slots:
    void updateUrlInBar(QUrl);
    void goToUrl();

    void on_actionClear_bookmarks_triggered();

    void on_saveToBookmarksButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
