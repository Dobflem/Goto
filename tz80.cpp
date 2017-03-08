#include "tz80.h"

bool TZ80::canEnterRoom() {
    return true;
}

QWidget* TZ80::getTimezoneWidget() {
    cout << "Returning 80s widget" << endl;
    return widget;
}
