#include "tz30.h"

void TZ30::enter(Backpack *b) {
    //Timezone::enter(b);
    this->setBackpack(b);
    if (!b->hasItem(40) && !this->widget->tokenVisible()) {
      this->getInfoMessage()->setMessage("So you need this token to get to the 40s..? Well the only way you're gonna get it is if you help us catch Al Capone! He keeps getting away from us! Catch him, and you can have your Token!");
      this->startPlaying();
    } else {
      if (this->widget->tokenVisible()) {
        this->getInfoMessage()->setMessage("Just take the damn token before I change my mind!");
      } else {
        this->getInfoMessage()->setMessage("Why would you want to come back to the 30s? Go on! get outta here!");
      }
    }
}

bool TZ30::canEnterRoom(Backpack *b) {
    return (b->hasItem(30));
}

void TZ30::setup() {
    QObject::connect(widget->getCapone(), SIGNAL(clicked()), this, SLOT(caughtCapone()));
    QObject::connect(widget->getToken(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));
    QObject::connect(this, SIGNAL(caponeXYchanged(int, int)), this->widget, SLOT(caponeGeometoryChanged(int, int)));
    QObject::connect(this, SIGNAL(caponeToggle()), this->widget, SLOT(toggleCapone()));
}

void TZ30::startPlaying() {
    this->playing = true;
    this->start();
}

void TZ30::run() {
    ClickableLabel *capone = this->widget->getCapone();
    int capone_width = capone->width();
    int capone_height = capone->height();
    int width = (this->widget->width()) - capone_width;
    int height = (this->widget->height()) - capone_height;
    int x = 0, y = 0;

    while(this->playing) {
        x = qrand() % width;
        y = qrand() % height;

        emit caponeXYchanged(x, y);

        emit caponeToggle();
        this_thread::sleep_for(chrono::milliseconds(1000));
        emit caponeToggle();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

QWidget* TZ30::getTimezoneWidget() {
    return widget;
}

void TZ30::stopPlaying() {
    this->playing = false;
}

void TZ30::leave() {
    Timezone::leaveTimezone();
    this->stopPlaying();
}

void TZ30::caughtCapone() {
    this->playing = false;
    this->widget->getCapone()->hide();
    this->widget->showToken();
    this->getInfoMessage()->setMessage("Good job kid! You took down a mobster! I'd advise you to take your token and leave.. unless you wanna get hit!");
}

void TZ30::tokenButtonPressed() {
    this->getBackpack()->addItem(new Item(40, "40s Token"));
    this->widget->getToken()->hide();
}
