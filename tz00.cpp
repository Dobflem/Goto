#include "tz00.h"

bool TZ00::canEnterRoom(Backpack* b) {
    return (b->hasItem(00));
}

QWidget* TZ00::getTimezoneWidget() {
    return widget;
}

void TZ00::enter(Backpack *b) {
    this->setBackpack(b);
    this->displayInfo();
}

void TZ00::leave() {
    // Timezone::leave();
}

void TZ00::setup() {
    widget = new tz00widget();
    tokenRecieved = false;
    QObject::connect(widget->getSubmitButton(), SIGNAL(clicked()), this, SLOT(submitButtonPressed()));
    QObject::connect(widget->getTokenButton(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));
}

void TZ00::displayInfo() {
    if (this->tokenRecieved) {
        displayAlreadyPassed();
    } else {
        Timezone::getInfoMessage()->setMessage("Welcome to the 00s. Tick the checkboxes corrisponding to the events of the noughties to pass the level");
    }
}

void TZ00::tokenButtonPressed() {
    this->tokenRecieved = true;
    this->widget->getTokenButton()->hide();

    displayAlreadyPassed();
    this->getBackpack()->addItem(new Item('10', "Present Token"));
}

void TZ00::displayAlreadyPassed() {
     Timezone::getInfoMessage()->setMessage("You have passed this level. Continue your adventure.");
}

void TZ00::submitButtonPressed() {
    if (answersCorrect()) {
        widget->getGameFrame()->hide();
        widget->getTokenButton()->show();
        Timezone::getInfoMessage()->setMessage("Well done. You have answered all questions correctly. Take your token to progress to the final level...");

    } else {
        this->widget->getWarningLabel()->show();
        QTimer::singleShot(5000, this->widget->getWarningLabel(), &QLabel::hide);
    }
}

bool TZ00::answersCorrect() {
    return (!widget->getTitanicCheckBox() &&
            !widget->getNelsonCheckBox() &&
             widget->getIpodCheckBox() &&
             widget->getMjCheckBox() &&
             widget->getBigBrotherCheckBox() &&
             widget->getYoutubeCheckBox());
}

