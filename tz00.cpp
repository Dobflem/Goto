#include "tz00.h"

bool TZ00::canEnterRoom() {
    return true;
}

QWidget* TZ00::getTimezoneWidget() {
    cout << "getting 00 widget" << endl;
    return widget;
}
