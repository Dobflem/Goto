#include "tz00.h"

bool TZ00::canEnterRoom() {
    return true;
}

QWidget* TZ00::getTimezoneWidget() {
    cout << "getting 00 widget" << endl;
    return widget;
}

void TZ00::enter(Backpack *b) {
    this->setBackpack(b);

    //start room description / functionality
}
