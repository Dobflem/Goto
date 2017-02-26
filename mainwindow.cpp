#include "mainwindow.h"
#include <iostream>
#include <QPixmap>
#include <QString>

#include "ui_mainwindow.h"
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

    this->tzPortal = new TZPortal("Time-Portal", "portal.jpg");
    this->tz20s = new TZ20("Twenties", "twenties.jpg");
    this->tz30s = new TZ30("Thirties", "thirties.jpg");
    this->tz40s = new TZ40("Fourties", "fourties.jpg");
    this->tz50s = new TZ50("Fifties", "fifties.jpg");
    this->tz60s = new TZ60("Sixties", "sixties.png");
    this->tz70s = new TZ70("Seventies", "seventies.jpg");
    this->tz80s = new TZ80("Eighties", "eighties.jpg");
    this->tz90s = new TZ90("Nineties", "nineties.jpg");
    this->tz00s = new TZ00("Noughties", "noughties.jpg");
    this->tzPresent = new TZPresent("Present Day", "today.jpg");

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
    if (tz != NULL) {
        this->setCurrentTimezone(tz);
    }
}

void MainWindow::moveNorth() {
    Timezone *tz = this->currentTimezone->getNorthTimezone();
    if (tz != NULL) {
        this->setCurrentTimezone(tz);
    }
}

void MainWindow::moveSouth() {
    Timezone *tz = this->currentTimezone->getSouthTimezone();
    if (tz != NULL) {
        this->setCurrentTimezone(tz);
    }
}

void MainWindow::moveWest() {
    Timezone *tz = this->currentTimezone->getWestTimezone();
    if (tz != NULL) {
        this->setCurrentTimezone(tz);
    }
}

void MainWindow::setCurrentTimezone(Timezone *tz) {
    this->currentTimezone = tz;
    this->setBackgroundImage(tz->getTZImage());
}

void MainWindow::setBackgroundImage(QString fileName) {
    QString resource = ":Resources/" + fileName;
    QPixmap image(resource);
    ui->tzImage->setPixmap(image);
}

void MainWindow::setMapImage(QString mapImage) {
    QString qstr = ":Resources/" + mapImage;
    QPixmap pix(qstr);
     ui->map_label->setPixmap(pix);
}

void MainWindow::setupSignalsAndSlots() {
    QObject::connect(ui->northButton, SIGNAL(clicked(bool)), this, SLOT(moveNorth()));
    QObject::connect(ui->southButton, SIGNAL(clicked(bool)), this, SLOT(moveSouth()));
    QObject::connect(ui->eastButton, SIGNAL(clicked(bool)), this, SLOT(moveEast()));
    QObject::connect(ui->westButton, SIGNAL(clicked(bool)), this, SLOT(moveWest()));
}
