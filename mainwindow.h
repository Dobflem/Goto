#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qstring.h>
#include <QPixmap>
#include <iostream>
#include "Timezone.h"

using namespace std;

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
    void on_northButton_clicked();
    void on_eastButton_clicked();
    void on_southButton_clicked();
    void on_westButton_clicked();

private:
    Ui::MainWindow *ui;
    Timezone *currentTimezone;
    void createTimezones();
    void goTimezone(string direction);
    void changeBackgroundImage(string fileName);
    void changeMapImage(string mapImage);
};

#endif // MAINWINDOW_H
