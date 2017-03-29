#include "tzportal.h"

bool TZPortal::canEnterRoom() {
    return true;
}

QWidget* TZPortal::getTimezoneWidget() {
    return widget;
}

void TZPortal::enter(Backpack *b) {
    this->setBackpack(b);
}
