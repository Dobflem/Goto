#include "tz00.h"

bool TZ00::canEnterRoom(Backpack* b) {
    return (b->hasItem(00));
}

QWidget* TZ00::getTimezoneWidget() {
    cout << "getting 00 widget" << endl;
    return widget;
}

void TZ00::enter(Backpack *b) {
    this->setBackpack(b);
    qDebug() << "Enter Noughties";
    this->displayInfo();
}

void TZ00::leave() {
    qDebug() << "Leaving 00s";
    // Timezone::leave();
}

void TZ00::displayInfo() {
    qDebug() << "display info in 00";
    if (this->tokenRecieved) {
         qDebug() << "display info in 00";
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
    if (!widget->getTitanicCheckBox() &&
         !widget->getNelsonCheckBox() &&
         widget->getIpodCheckBox() &&
         widget->getMjCheckBox() &&
         widget->getBigBrotherCheckBox() &&
         widget->getYoutubeCheckBox()) {
        return true;
    } else {
        return false;
    }
}

