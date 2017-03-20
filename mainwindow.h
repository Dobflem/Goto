#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QWidget>
#include <QLayoutItem>
#include <iostream>
// #include <QtMultimedia/QMediaPlayer>
#include <QFileInfo>
#include "Timezone.h"
#include "backpack.h"
#include "infomessage.h"

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

public slots:
    void setInfoText(QString);
    void setBackpackText(QString);

private slots:
    void moveNorth();
    void moveSouth();
    void moveEast();
    void moveWest();
    void on_viewBackpackItemsButton_clicked();

private:
    Ui::MainWindow *ui;
    Timezone *currentTimezone, *tzPortal, *tz20s, *tz30s, *tz40s, *tz50s, *tz60s, *tz70s, *tz80s, *tz90s, *tz00s, *tzPresent;
    QWidget *currentTZWidget;
    Backpack *backpack;
    // QMediaPlayer* music;

    void createTimezones();
    void goTimezone(QString direction);
    void setupSignalsAndSlots();
    void setBackpackSignalandSlot();
    // void changeSong();
    void setTimezoneExits();
    void addTokensToRooms();
    void addOtherItemsToRooms();
    void setupBackpackButtonSettings();

    // GETTERS
    Timezone getCurrentTimezone();

    // SETTERS
    void setBackgroundImage(QString fileName);
    void setCurrentTimezone(Timezone *tz);
    void setInformationText(QString txt);
    void setMapImage(QString mapImage);
    void setArrows();

};

#endif // MAINWINDOW_H
