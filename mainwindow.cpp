#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GoToTime.h"
#include <QPixmap>
#include <string>
#include <qstring.h>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
        ui->setupUi(this);
        changeMapImage("map.png");
        changeBackgroundImage("portal.jpg");
        ui->northButton->setArrowType(Qt::UpArrow);
        ui->southButton->setArrowType(Qt::DownArrow);
        ui->eastButton->setArrowType(Qt::RightArrow);
        ui->westButton->setArrowType(Qt::LeftArrow);

        QString qstr = QString::fromStdString("You are currently in the time portal. Start exploring to make your way back to the present day :)");
        ui->textEdit->setText(qstr);

        //QObject::connect(ui->goEastButton, SIGNAL(clicked()), GoToTime,  SLOT(goTimezoneSlot(string direction)));

        createTimezones();
    }

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::changeBackgroundImage(string fileName) {
    QString qstr = QString::fromStdString(":Resources/" + fileName);
    QPixmap pix(qstr);
     ui->label->setPixmap(pix);
}

void MainWindow::changeMapImage(string mapImage) {
    QString qstr = QString::fromStdString(":Resources/" + mapImage);
    QPixmap pix(qstr);
     ui->map_label->setPixmap(pix);
}

void MainWindow::on_northButton_clicked() {

    goTimezone("north");
}

void MainWindow::on_eastButton_clicked() {
    goTimezone("east");
}

void MainWindow::on_southButton_clicked() {
    goTimezone("south");
}

void MainWindow::on_westButton_clicked() {
     goTimezone("west");
}

void MainWindow::createTimezones()  {
    Timezone *tzTimePortal, *tz20s, *tz30s, *tz40s, *tz50s, *tz60s, *tz70s, *tz80s, *tz90s, *tz00s, *tzPresentDay;

    tzTimePortal = new Timezone("Time-Portal", "portal.jpg");
    tz20s = new Timezone("Twenties", "twenties.jpg");
    tz30s = new Timezone("Thirties", "thirties.jpg");
    tz40s = new Timezone("Fourties", "fourties.jpg");
    tz50s = new Timezone("Fifties", "fifties.jpg");
    tz60s = new Timezone("Sixties", "sixties.png");
    tz70s = new Timezone("Seventies", "seventies.jpg");
    tz80s = new Timezone("Eighties", "eighties.jpg");
    tz90s = new Timezone("Nineties", "nineties.jpg");
    tz00s = new Timezone("Noughties", "noughties.jpg");
    tzPresentDay = new Timezone("Present Day", "today.jpg");

    // (N, E, S, W)
    tzTimePortal->setExits(tz60s, tz20s, tz80s, tz00s);
    tz20s->setExits(tz30s, NULL, tz40s, tzTimePortal);
    tz30s->setExits(tz50s, NULL, tz20s, NULL);
    tz40s->setExits(tz20s, NULL, NULL, NULL);
    tz50s->setExits(NULL, NULL, tz30s, NULL);
    tz60s->setExits(tz70s, NULL, tzTimePortal, NULL);
    tz70s->setExits(NULL, NULL, tz60s, tz90s);
    tz80s->setExits(tzTimePortal, NULL, NULL, NULL);
    tz90s->setExits(NULL, tz70s, NULL, NULL);
    tz00s->setExits(NULL, tzTimePortal, tzPresentDay, NULL);
    tzPresentDay->setExits(tz00s, NULL, NULL, NULL);

   currentTimezone = tzTimePortal;
}

void MainWindow::goTimezone(string direction ) {
    Timezone* nextTimezone = currentTimezone->nextTimezone(direction);
    if (nextTimezone == NULL) {
        ui->textEdit->setText("Oopsie, there is no timezone in that direction!!");
    } else {
        currentTimezone = nextTimezone;
        changeBackgroundImage(currentTimezone->getImagePath());
        QString qstr = QString::fromStdString("Current Timezone: " + currentTimezone->shortDescription());
        ui->textEdit->setText(qstr);
    }
}
