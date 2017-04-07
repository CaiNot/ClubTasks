#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDial>
#include <QTimer>
#include <QLCDNumber>

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
    void on_dial_actionTriggered(int action);
    void changetime();

signals:
    void get_time(int x);


private:
    Ui::MainWindow *ui;
    QTimer *timer;

    int i=0;
};

#endif // MAINWINDOW_H
