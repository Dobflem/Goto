#include "include/tz90.h"

bool TZ90::canEnterRoom() {
    return true;
}

QWidget* TZ90::getTimezoneWidget() {
   cout << "getting 90 widget" << endl;
    return widget;
}
