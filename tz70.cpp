#include "tz70.h"

bool TZ70::canEnterRoom() {
    return true;
}

QWidget* TZ70::getTimezoneWidget() {
    return widget;
}

void TZ70::setupSignalsAndSlots() {
    QObject::connect(this->volumeDial, SIGNAL(valueChanged(int)), this->volumeLCD, SLOT(display(int)));
    QObject::connect(this->volumeDial, SIGNAL(valueChanged(int)), this, SLOT(changedVolume(int)));
}

void TZ70::changedVolume(int vol) {
    if ((vol == 100) && (!this->getBackpack()->hasItem(80))) {
        // Show Token
    }
}
