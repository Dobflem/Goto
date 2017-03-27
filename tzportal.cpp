#include "tzportal.h"

bool TZPortal::canEnterRoom() {
    return true;
}

QWidget* TZPortal::getTimezoneWidget() {
    return widget;
}
