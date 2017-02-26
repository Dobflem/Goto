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
    void moveNorth();
    void moveSouth();
    void moveEast();
    void moveWest();

private:
    Ui::MainWindow *ui;
    Timezone *currentTimezone, *tzPortal, *tz20s, *tz30s, *tz40s, *tz50s, *tz60s, *tz70s, *tz80s, *tz90s, *tz00s, *tzPresent;

    void createTimezones();
    void goTimezone(QString direction);
    void setupSignalsAndSlots();

    // GETTERS
    Timezone getCurrentTimezone();

    // SETTERS
    void setBackgroundImage(QString fileName);
    void setCurrentTimezone(Timezone *tz);
    void setMapImage(QString mapImage);
};

#endif // MAINWINDOW_H
