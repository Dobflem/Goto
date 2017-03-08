#include "tzpresent.h"

bool TZPresent::canEnterRoom() {
    return true;
}

QWidget* TZPresent::getTimezoneWidget() {
    cout << "getting present widget" << endl;
    return widget;
}
