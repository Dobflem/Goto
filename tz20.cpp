#include "tz20.h"

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

void TZ20::setup() {
    QObject::connect(widget->getButton(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));
    QObject::connect(widget->getKeyButton(), SIGNAL(clicked()), this, SLOT(keyButtonPressed()));
}

void TZ20::displayInfo() {
    if (this->tokenRecieved) {
        displayAlreadyPassed();
    } else {
        Timezone::getInfoMessage()->setMessage("Welcome to the roaring 20s. In order to collect the timezone token to enter the 30s.... Please select the timezone token button on the screen");
    }
}

void TZ20::displayAlreadyPassed() {
    Timezone::getInfoMessage()->setMessage("You have passed this level. Continue your adventure.");
}

void TZ20::tokenButtonPressed() {
    this->tokenRecieved = true;
    this->widget->getButton()->hide();

    displayAlreadyPassed();
    this->getBackpack()->addItem(new Item(30, "30s Token"));
}

void TZ20::keyButtonPressed() {
    this->widget->getKeyButton()->hide();

    this->getBackpack()->addItem(new Item(21, "Unlock 80s question"));
}
