#include "tz20.h"

bool TZ20::canEnterRoom() {
    return true;
}

QWidget* TZ20::getTimezoneWidget() {
    return this->widget;
}
