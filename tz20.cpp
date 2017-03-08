#include "tz20.h"

bool TZ20::canEnterRoom() {
    return true;
}

QWidget* TZ20::getTimezoneWidget() {
    cout << "getting 20 widget" << endl;
    return widget;
}
