#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QPixmap>
#include <QString>
#include <QThread>
#include <QDebug>

#include "GoToTime.h"
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

#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
        ui->setupUi(this);

        this->setArrows();
        this->setupBackpackButtonSettings();



        this->currentTimezone = NULL;
        this->backpack = new Backpack();

        this->setBackpackSignalandSlot();
        this->backpack->addItem(new Item(20, "20s Token"));
        // this->music = new QMediaPlayer();

        this->createTimezones();
        this->setTimezoneExits();
        this->addTokensToRooms();
        this->addOtherItemsToRooms();
        this->setCurrentTimezone(tzPortal);
        this->setupSignalsAndSlots();
    }

MainWindow::~MainWindow() {
    delete this->tzPortal;
    delete this->tz20s;
    delete this->tz30s;
    delete this->tz40s;
    delete this->tz50s;
    delete this->tz60s;
    delete this->tz70s;
    delete this->tz80s;
    delete this->tz90s;
    delete this->tz00s;
    delete this->tzPresent;
    delete this->backpack;
    // delete this->music;
    delete ui;
}

void MainWindow::createTimezones()  {
    this->tzPortal = new TZPortal();
    this->tz20s = new TZ20();
    this->tz30s = new TZ30();
    this->tz40s = new TZ40();
    this->tz50s = new TZ50();
    this->tz60s = new TZ60();
    this->tz70s = new TZ70();
    this->tz80s = new TZ80();
    this->tz90s = new TZ90();
    this->tz00s = new TZ00();
    this->tzPresent = new TZPresent();
}

void MainWindow::setArrows() {
    ui->northButton->setArrowType(Qt::UpArrow);
    ui->southButton->setArrowType(Qt::DownArrow);
    ui->eastButton->setArrowType(Qt::RightArrow);
    ui->westButton->setArrowType(Qt::LeftArrow);
}

void MainWindow::setupBackpackButtonSettings() {
    QPixmap pixmap(":Resources/backpack_icon.png");
    QIcon ButtonIcon(pixmap);
    ui->viewBackpackItemsButton->setIcon(ButtonIcon);
    ui->viewBackpackItemsButton->setIconSize(QSize(35, 35));

    ui->backpackContents->hide();
}

void MainWindow::setTimezoneExits() {
    // (N, E, S, W)
    this->tzPortal->setExits(tz60s, tz20s, tz80s, tz00s);
    this->tz20s->setExits(tz30s, NULL, tz40s, tzPortal);
    this->tz30s->setExits(tz50s, NULL, tz20s, NULL);
    this->tz40s->setExits(tz20s, NULL, NULL, NULL);
    this->tz50s->setExits(NULL, NULL, tz30s, NULL);
    this->tz60s->setExits(tz70s, NULL, tzPortal, NULL);
    this->tz70s->setExits(NULL, NULL, tz60s, tz90s);
    this->tz80s->setExits(tzPortal, NULL, NULL, NULL);
    this->tz90s->setExits(NULL, tz70s, NULL, NULL);
    this->tz00s->setExits(NULL, tzPortal, tzPresent, NULL);
    this->tzPresent->setExits(tz00s, NULL, NULL, NULL);
}

void MainWindow::addTokensToRooms() {
    this->tz20s->addItem(new Item(30, "30s Token"));
    this->tz30s->addItem(new Item(40, "40s Token"));
    this->tz40s->addItem(new Item(50, "50s Token"));
    this->tz50s->addItem(new Item(60, "60s Token"));
    this->tz60s->addItem(new Item(70, "70s Token"));
    this->tz70s->addItem(new Item(80, "80s Token"));
    this->tz80s->addItem(new Item(90, "90s Token"));
    this->tz90s->addItem(new Item(00, "00s Token"));
    this->tz00s->addItem(new Item(10, "Present Token"));
}

void MainWindow::addOtherItemsToRooms() {
    this->tz20s->addItem(new Item(81, "Unlock 80s Question Key"));
}

void MainWindow::moveEast() {
    Timezone *tz = this->currentTimezone->getEastTimezone();
    this->setCurrentTimezone(tz);
}

void MainWindow::moveNorth() {
    Timezone *tz = this->currentTimezone->getNorthTimezone();
    this->setCurrentTimezone(tz);
}

void MainWindow::moveSouth() {
    Timezone *tz = this->currentTimezone->getSouthTimezone();
    this->setCurrentTimezone(tz);
}

void MainWindow::moveWest() {
    Timezone *tz = this->currentTimezone->getWestTimezone();
    this->setCurrentTimezone(tz);
}

void MainWindow::setBackpackText(QString txt) {
    cout << "setting backpack text to: " << txt.toStdString() << endl;

    ui->backpackContents->setText(txt);
    ui->backpackContents->repaint();
}

void MainWindow::setInfoText(QString txt) {
    /*
    for (int i = 1; i <= txt.length(); i++) {
        ui->txtInfo->setText(txt.left(i));
        // Have to manually call repaint
        // Qt does a smart refresh to stop flickering
        // This means if we don't add a repaint
        // the text box won't update until outside the loop.
        ui->txtInfo->repaint();
        // We wait 16ms for that SLICK text effect.
        QThread::msleep(16);
    }
    */
    ui->txtInfo->setText(txt);
    ui->txtInfo->repaint();
}

void MainWindow::setCurrentTimezone(Timezone *tz) {
    // Check if there is a room to move to
   // qDebug() << "setCurrentTimezone();";
    if (tz != NULL) {
     //   qDebug() << "tz != NULL;";
        // Check if we can enter the room
        // This is a VIRTUAL method
        // The super method always returns true
        if (tz->canEnterRoom(this->backpack)) {

       //     qDebug() << "tz->canEnterRoom();";
            // Remove the current widget so multiple don't show
            if (this->currentTZWidget != NULL) {
         //       qDebug() << "Removing widget";
                ui->gridLayout->removeWidget(this->currentTZWidget);
            }

            // Need to store the current timezone so the signals know which slots to call
            if (this->currentTimezone != NULL) {
           //     qDebug() << "Leaving room";
                this->currentTimezone->leave();
            }

            this->currentTimezone = tz;

            // Setup the map image
            // We don't need to store this because we don't reference it anywhere else
            //qDebug() << "Setting map image";
            this->setMapImage(this->currentTimezone->getMapPath());
            //qDebug() << "Map image set";

            // Set up the Widgets
            this->currentTZWidget = this->currentTimezone->getTimezoneWidget();
            //qDebug() << "Adding widget";
            ui->gridLayout->addWidget(this->currentTZWidget);
            //qDebug() << "Widget added";

            // Make sure we call raise or else it will not be brought to front.
            //qDebug() << "Raising widget";
            this->currentTZWidget->raise();
            //qDebug() << "Widget raised";

            // Change the music to the current timezone track
            // this->changeSong();

            //qDebug() << "Entering room";
            this->currentTimezone->enter(this->backpack);
            //qDebug() << "Room entered";

        } else {
            //qDebug() << "Room Locked";
            this->currentTimezone->getInfoMessage()->setMessage(tz->getDescription().append(" is currently locked. Please find token first."));
        }
    }
}

/*
void MainWindow::changeSong() {
    QString resource = "qrc:Resources/" + this->currentTimezone->getMusicPath();
    music->setMedia(QUrl(resource));
    music->setVolume(7);
    music->play();
}
*/

void MainWindow::setMapImage(QString mapImage) {
    QString resource = ":Resources/" + mapImage;
    QPixmap image(resource);
    ui->map_label->setPixmap(image);
}

void MainWindow::setBackgroundImage(QString fileName) {
    QString resource = ":Resources/" + fileName;
    QPixmap image(resource);
    ui->tzImage->setPixmap(image);
}

void MainWindow::setupSignalsAndSlots() {
    QObject::connect(ui->northButton, SIGNAL(clicked(bool)), this, SLOT(moveNorth()));
    QObject::connect(ui->southButton, SIGNAL(clicked(bool)), this, SLOT(moveSouth()));
    QObject::connect(ui->eastButton, SIGNAL(clicked(bool)), this, SLOT(moveEast()));
    QObject::connect(ui->westButton, SIGNAL(clicked(bool)), this, SLOT(moveWest()));

    QObject::connect(this->tz20s->getInfoMessage(), SIGNAL(valueChanged(QString)), this, SLOT(setInfoText(QString)));
    QObject::connect(this->tz30s->getInfoMessage(), SIGNAL(valueChanged(QString)), this, SLOT(setInfoText(QString)));
    QObject::connect(this->tz40s->getInfoMessage(), SIGNAL(valueChanged(QString)), this, SLOT(setInfoText(QString)));
    QObject::connect(this->tz50s->getInfoMessage(), SIGNAL(valueChanged(QString)), this, SLOT(setInfoText(QString)));
    QObject::connect(this->tz60s->getInfoMessage(), SIGNAL(valueChanged(QString)), this, SLOT(setInfoText(QString)));
    QObject::connect(this->tz70s->getInfoMessage(), SIGNAL(valueChanged(QString)), this, SLOT(setInfoText(QString)));
    QObject::connect(this->tz80s->getInfoMessage(), SIGNAL(valueChanged(QString)), this, SLOT(setInfoText(QString)));
    QObject::connect(this->tz90s->getInfoMessage(), SIGNAL(valueChanged(QString)), this, SLOT(setInfoText(QString)));
    QObject::connect(this->tz00s->getInfoMessage(), SIGNAL(valueChanged(QString)), this, SLOT(setInfoText(QString)));
    QObject::connect(this->tzPortal->getInfoMessage(), SIGNAL(valueChanged(QString)), this, SLOT(setInfoText(QString)));
    QObject::connect(this->tzPresent->getInfoMessage(), SIGNAL(valueChanged(QString)), this, SLOT(setInfoText(QString)));
}

void MainWindow::setBackpackSignalandSlot() {
   QObject::connect(this->backpack->getContents(), SIGNAL(valueChanged(QString)), this, SLOT(setBackpackText(QString)));
}

void MainWindow::on_viewBackpackItemsButton_clicked() {
    if (ui->backpackContents->isHidden()) {
         ui->backpackContents->show();
    } else {
        ui->backpackContents->hide();
    }
}
