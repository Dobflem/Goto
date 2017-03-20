#include "tz20.h"
#include "clickablelabel.h"

#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QMouseEvent>
#include <QDebug>

bool TZ20::canEnterRoom(Backpack *b) {
    return (b->hasItem(20));
}

QWidget* TZ20::getTimezoneWidget() {
    return this->widget;
}

void TZ20::enter(Backpack *b) {
    this->setBackpack(b);
    this->displayInfo();
}

void TZ20::run() {
    qDebug() << "running";
}

void TZ20::displayInfo() {

    if (this->tokenRecieved) {
        displayAlreadyPassed();
    } else {
        Timezone::getInfoMessage()->setMessage("Welcome to the roaring 20s");
        Timezone::getInfoMessage()->setMessage("");
        usleep(50000);
        Timezone::getInfoMessage()->setMessage("In order to collect the timezone token to enter the 30s.... Please select the timezone token button on the screen");
    }
}

void TZ20::displayAlreadyPassed() {
    Timezone::getInfoMessage()->setMessage("You have passed this level. Continue your adventure.");
}

void TZ20::leave() {
    qDebug() << "Leaving";
    // Timezone::leave();
}

void TZ20::tokenButtonPressed() {
    this->tokenRecieved = true;
    this->widget->getButton()->hide();

    displayAlreadyPassed();

    if (isItemInTimezone(30)) {
        int location = getLocationOfItemInTimezone(30);
        Timezone::getBackpack()->addItem(&itemsInTimezone[location]);
        removeItemFromTimezone(location);
    }
}

void TZ20::keyButtonPressed() {
    this->widget->getKeyButton()->hide();

    if (isItemInTimezone(81)) {
        int location = getLocationOfItemInTimezone(81);
        Timezone::getBackpack()->addItem(&itemsInTimezone[location]);
        removeItemFromTimezone(location);
    }
}
