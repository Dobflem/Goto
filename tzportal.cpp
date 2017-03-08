#include "tzportal.h"

bool TZPortal::canEnterRoom() {
    return true;
}

QWidget* TZPortal::getTimezoneWidget() {
    cout << "Getting portal widget" << endl;
    return widget;
}
