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
    this->startPlaying();
}

bool TZ30::canEnterRoom() {
    return true;
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
        capone->setGeometry(x, y, capone_width, capone_height);
        capone->show();
        this_thread::sleep_for(chrono::milliseconds(1000));
        capone->hide();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

QWidget* TZ30::getTimezoneWidget() {
    return widget;
}

void TZ30::stopPlaying() {
    qDebug() << "Setting playing - false";
    this->playing = false;
}

void TZ30::leave() {
    this->stopPlaying();
    // Timezone::leave();
}

void TZ30::caughtCapone() {
    qDebug() << "You caught Capone!";
}
