#include "tz70.h"

bool TZ70::canEnterRoom() {
    return true;
}

QWidget* TZ70::getTimezoneWidget() {
    cout << "getting 70 widget" << endl;
    return widget;
}
