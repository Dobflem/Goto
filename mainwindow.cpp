#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QPixmap>
#include <QString>
#include <QThread>

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

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
        ui->setupUi(this);

        ui->northButton->setArrowType(Qt::UpArrow);
        ui->southButton->setArrowType(Qt::DownArrow);
        ui->eastButton->setArrowType(Qt::RightArrow);
        ui->westButton->setArrowType(Qt::LeftArrow);

        this->createTimezones();
        this->setupSignalsAndSlots();

        //ui->gridLayout->addWidget(currentTimezone->getTimezoneWidget());
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
    delete ui;
}

void MainWindow::createTimezones()  {

    this->tzPortal = new TZPortal("Time-Portal", "portal.jpg", "map.png");
    this->tz20s = new TZ20("Twenties", "twenties.jpg", "map-20s.png");
    this->tz30s = new TZ30("Thirties", "thirties.jpg", "map-30s.png");
    this->tz40s = new TZ40("Fourties", "fourties.jpg", "map-40s.png");
    this->tz50s = new TZ50("Fifties", "fifties.jpg", "map-50s.png");
    this->tz60s = new TZ60("Sixties", "sixties.png", "map-60s.png");
    this->tz70s = new TZ70("Seventies", "seventies.jpg", "map-70s.png");
    this->tz80s = new TZ80("Eighties", "eighties.jpg", "map-80s.png");
    this->tz90s = new TZ90("Nineties", "nineties.jpg", "map-90s.png");
    this->tz00s = new TZ00("Noughties", "noughties.jpg", "map-00s.png");
    this->tzPresent = new TZPresent("Present Day", "today.jpg", "map-present.png");

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

    this->setCurrentTimezone(tzPortal);
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

void MainWindow::setCurrentTimezone(Timezone *tz) {
    // Check if there is a room to move to
    if (tz != NULL) {
        // Check if we can enter the room
        // This is a VIRTUAL method
        // The super method always returns true
        if (tz->canEnterRoom()) {

            //TODO: add deletion of widget in view before adding new widget
            // currently not working
            /*QWidget* wid = currentTimezone->getTimezoneWidget();
            ui->gridLayout->removeWidget(wid);
            delete wid;*/

            this->currentTimezone = tz;

            //getTimezoneWidget is a virtual method

             ui->gridLayout->addWidget(currentTimezone->getTimezoneWidget());
             setMapImage(currentTimezone->getMapPath());

        } else {
            this->setInformationText("This room is currently locked. Please find token first.");
        }
    }
}

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

void MainWindow::setInformationText(QString txt) {
    for (int i = 1; i <= txt.length(); i++) {
        ui->txtInfo->setText(txt.left(i));
        // Have to manually call repaint
        // Qt does a smart refresh to stop flickering
        // This means if we don't add a repaint
        // the text box won't update until outside the loop.
        ui->txtInfo->repaint();
        QThread::msleep(16);
    }
}

void MainWindow::setupSignalsAndSlots() {
    QObject::connect(ui->northButton, SIGNAL(clicked(bool)), this, SLOT(moveNorth()));
    QObject::connect(ui->southButton, SIGNAL(clicked(bool)), this, SLOT(moveSouth()));
    QObject::connect(ui->eastButton, SIGNAL(clicked(bool)), this, SLOT(moveEast()));
    QObject::connect(ui->westButton, SIGNAL(clicked(bool)), this, SLOT(moveWest()));
}
