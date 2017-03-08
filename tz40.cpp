#include "tz40.h"

bool TZ40::canEnterRoom() {
    return true;
}

QWidget* TZ40::getTimezoneWidget() {
    cout << "getting 40 widget" << endl;
    return widget;
}
