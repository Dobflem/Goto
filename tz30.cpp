#include "tz30.h"
#include "tz30widget.h"

#include <thread>
#include <chrono>

#include "clickablelabel.h"

#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QMouseEvent>

void TZ30::enter(Backpack *b) {
    Timezone::enter(b);
    if (!b->hasItem(40) && !this->widget->tokenVisible()) {
      this->startPlaying();
    }
}

bool TZ30::canEnterRoom(Backpack *b) {
    return (b->hasItem(30));
    //return true;
}

void TZ30::startPlaying() {
    qDebug() << "Setting playing - true";
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
    this->stopPlaying();
}

void TZ30::caughtCapone() {
    this->playing = false;
    this->widget->showToken();
}

void TZ30::tokenButtonPressed() {
    this->getBackpack()->addItem(new Item(40, "40s Token"));
    this->widget->getToken()->hide();
}
