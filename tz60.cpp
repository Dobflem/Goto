#include "include/tz60.h"

bool TZ60::canEnterRoom() {
    return true;
}

QWidget* TZ60::getTimezoneWidget() {
    cout << "Getting 60s widget" << endl;
    return widget;
}
