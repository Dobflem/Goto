#include "tz90.h"

bool TZ90::canEnterRoom(Backpack *b) {
    return (b->hasItem(90));
}

void TZ90::enter(Backpack *b) {
    this->setBackpack(b);
    if (!this->getBackpack()->hasItem(0)) {
        this->getInfoMessage()->setMessage("Just take the token.");
    } else {
        this->getInfoMessage()->setMessage("Oh, you're back..");
    }
}

QWidget* TZ90::getTimezoneWidget() {
    return widget;
}

void TZ90::transparentTokenClicked() {
    this->getBackpack()->addItem(new Item(0, "Noughties Token"));
    this->widget->getTokenTransparent()->hide();
    this->getInfoMessage()->setMessage("Awh.. you found it.. well my fun's over..");
}

void TZ90::clickedToken() {
    this->widget->getToken()->hide();
    this->widget->getTokenTransparent()->show();
    this->getInfoMessage()->setMessage("You thought it would be that easy.. HA! I laugh at you! Try find it now that it's invisible!");
}

void TZ90::setupSignalsAndSlots() {
    QObject::connect(this->widget->getToken(), SIGNAL(clicked(bool)), this, SLOT(clickedToken()));
    QObject::connect(this->widget->getTokenTransparent(), SIGNAL(clicked()), this, SLOT(transparentTokenClicked()));
}
