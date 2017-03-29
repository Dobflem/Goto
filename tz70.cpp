#include "tz70.h"

void TZ70::enter(Backpack* b) {
    this->setBackpack(b);
    if (!this->getBackpack()->hasItem(80)) {
        this->getInfoMessage()->setMessage("Hey man! Can you turn up the volume?");
    }
}

bool TZ70::canEnterRoom(Backpack *b) {
    return (b->hasItem(70));
}

QWidget* TZ70::getTimezoneWidget() {
    return widget;
}

void TZ70::changedVolume(int vol) {
    if ((vol == 100) && (!this->getBackpack()->hasItem(80))) {
        this->widget->getToken()->show();
        this->getInfoMessage()->setMessage("Thanks man!");
    }
}

void TZ70::clickedToken() {
    this->getBackpack()->addItem(new Item(80, "80s Token"));
    this->widget->getToken()->hide();
}

void TZ70::setupSignalsAndSlots() {
    QObject::connect(this->volumeDial, SIGNAL(valueChanged(int)), this->volumeLCD, SLOT(display(int)));
    QObject::connect(this->volumeDial, SIGNAL(valueChanged(int)), this, SLOT(changedVolume(int)));
    QObject::connect(this->widget->getToken(), SIGNAL(clicked()), this, SLOT(clickedToken()));
}
