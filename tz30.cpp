#include "tz30.h"

bool TZ30::canEnterRoom() {
    return false;
}

QWidget* TZ30::getTimezoneWidget() {
    cout << "getting 30 widget" << endl;
    return widget;
}
