#include "tz70.h"

bool TZ70::canEnterRoom(Backpack *b) {
    return (b->hasItem(70));
}

QWidget* TZ70::getTimezoneWidget() {
    return widget;
}

void TZ70::setup() {
    this->widget = new tz70widget();
    this->volumeDial = this->widget->getVolumeDial();
    this->volumeLCD = this->widget->getVolumeLCD();
    this->setupSignalsAndSlots();
}

void TZ70::changedVolume(int vol) {
    if ((vol == 100) && (!this->getBackpack()->hasItem(80))) {
        this->widget->getToken()->show();
    }
}

void TZ70::clickedToken(bool clicked) {
    this->getBackpack()->addItem(new Item(80, "80s Token"));
    this->widget->getToken()->hide();
}

void TZ70::setupSignalsAndSlots() {
    QObject::connect(this->volumeDial, SIGNAL(valueChanged(int)), this->volumeLCD, SLOT(display(int)));
    QObject::connect(this->volumeDial, SIGNAL(valueChanged(int)), this, SLOT(changedVolume(int)));
    QObject::connect(this->widget->getToken(), SIGNAL(clicked(bool)), this, SLOT(clickedToken(bool)));
}
