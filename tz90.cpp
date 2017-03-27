#include "tz90.h"

bool TZ90::canEnterRoom(Backpack *b) {
    return (b->hasItem(90));
}

QWidget* TZ90::getTimezoneWidget() {
    return widget;
}

void TZ90::transparentTokenClicked() {
    this->getBackpack()->addItem(new Item(0, "Naughties Token"));
    this->widget->getTokenTransparent()->hide();
}

void TZ90::clickedToken(bool clicked) {
    this->widget->getToken()->hide();
    this->widget->getTokenTransparent()->show();
}

void TZ90::setupSignalsAndSlots() {
    QObject::connect(this->widget->getToken(), SIGNAL(clicked(bool)), this, SLOT(clickedToken(bool)));
    QObject::connect(this->widget->getTokenTransparent(), SIGNAL(clicked()), this, SLOT(transparentTokenClicked()));
}
