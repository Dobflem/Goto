#include "include/tz50.h"

bool TZ50::canEnterRoom() {
    return true;
}

QWidget* TZ50::getTimezoneWidget() {
   cout << "getting 60 widget" << endl;
    return widget;
}
