#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// QIncludes
#include <QMainWindow>
#include <QPixmap>
#include <QWidget>
#include <QLayoutItem>
#include <QFileInfo>
#include <QString>
#include <QThread>
#include <QDebug>

#ifdef _WIN32
#include <QtMultimedia/QMediaPlayer>
#endif

//StdIncludes
#include <iostream>

//CustomIncludes
#include "Timezone.h"
#include "backpack.h"
#include "infomessage.h"
#include "tzportal.h"
#include "tz20.h"
#include "tz30.h"
#include "tz40.h"
#include "tz50.h"
#include "tz60.h"
#include "tz70.h"
#include "tz80.h"
#include "tz90.h"
#include "tz00.h"
#include "tzpresent.h"

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
    void setInfoText(const QString&);
    void setBackpackText(const QString&);

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

    #ifdef _WIN32
    QMediaPlayer* music;
    #endif

    void createTimezones();
    void goTimezone(const QString& direction);
    void setupSignalsAndSlots();
    void setBackpackSignalandSlot();
    void setTimezoneExits();
    void setupBackpackButtonSettings();
    #ifdef _WIN32
    void changeSong();
    #endif

    // GETTERS
    Timezone* getCurrentTimezone();

    // SETTERS
    void setBackgroundImage(const QString& fileName);
    void setCurrentTimezone(Timezone *tz);
    void setInformationText(const QString& txt);
    void setMapImage(const QString& mapImage);
    void setArrows();

};

#endif // MAINWINDOW_H
