#include "tz20.h"

bool TZ20::canEnterRoom(Backpack *b) {
    //hasItem method not working
    //return (b->hasItem(20));

    return true;
}

QWidget* TZ20::getTimezoneWidget() {
    return this->widget;
}

void TZ20::enter(Backpack *b) {
    this->setBackpack(b);

    //start room description / functionality
    this->displayInfo();
}

void TZ20::displayInfo() {
    Timezone::getInfoMessage()->setMessage("Welcome to the roaring 20s. An age of dramatic social and political revolution.");
    //Timezone::getInfoMessage()->setMessage("In order to collect the timezone token to enter the 30s.... Please select the timezone token button on the screen");
}
