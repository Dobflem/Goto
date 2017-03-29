#include "tz80.h"
#include <QTimer>

bool TZ80::canEnterRoom(Backpack *b) {
    return (b->hasItem(80));
}

QWidget* TZ80::getTimezoneWidget() {
    return widget;
}

void TZ80::enter(Backpack *b) {
    this->setBackpack(b);
    this->displayInfo();

    showHideUnlockQuestionButton();
}

void TZ80::leave() {
    // Timezone::leave();
}

void TZ80::setup() {
    setupHideUIElements();
    setupSignalsAndSlotConnections();
}

void TZ80::setupHideUIElements() {
    this->widget->getWarningLabel()->hide();
    this->widget->getTokenButton()->hide();
    this->widget->getQuizFrame()->hide();
}

void TZ80::setupSignalsAndSlotConnections() {
    QObject::connect(widget->getSubmitButton(), SIGNAL(clicked()), this, SLOT(submitAnswersButtonPressed()));
    QObject::connect(widget->getTokenButton(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));
    QObject::connect(widget->getStartButton(), SIGNAL(clicked()), this, SLOT(startButtonPressed()));
    QObject::connect(widget->getCloseButton(), SIGNAL(clicked()), this, SLOT(closeButtonPressed()));
    QObject::connect(widget->getUnlockQuestionButton(), SIGNAL(clicked()), this, SLOT(unlockQuestionButtonPressed()));
}

void TZ80::showHideUnlockQuestionButton() {
    if (this->getBackpack()->hasItem(81)) {
        this->widget->getUnlockQuestionButton()->show();
    } else {
        this->widget->getUnlockQuestionButton()->hide();
    }
}

void TZ80::displayInfo() {
    if (this->tokenRecieved) {
        displayAlreadyPassed();
    } else {
        Timezone::getInfoMessage()->setMessage("Welcome to the 1980s. To pass this level and receive the timzone token for the 90s.... Answer each of the trivia questions correctly");
    }
}

void TZ80::displayAlreadyPassed() {
    Timezone::getInfoMessage()->setMessage("You have passed this level. Continue your adventure.");
}

void TZ80::unlockQuestionButtonPressed() {
    this->widget->getLockedQuestionFrame()->hide();
    this->widget->getUnlockQuestionButton()->hide();
    Timezone::getBackpack()->removeItem(81);
}


void TZ80::submitAnswersButtonPressed() {
    int a1 = this->widget->getQ1ComboBox()->currentIndex();
    int a2 = this->widget->getQ2ComboBox()->currentIndex();
    int a3 = this->widget->getQ3ComboBox()->currentIndex();
    int a4 = this->widget->getQ4ComboBox()->currentIndex();

    if (allAnswersCorrect(a1, a2, a3, a4)) {
        this->widget->getQuizFrame()->hide();
        this->widget->getTokenButton()->show();
        Timezone::getInfoMessage()->setMessage("Congratulations. You have answered all questions correctly. Select your 90s timezon token to put it in your backpack");
    } else {
        this->widget->getWarningLabel()->show();
        QTimer::singleShot(5000, this->widget->getWarningLabel(), &QLabel::hide);
    }
}

bool TZ80::allAnswersCorrect(int a1, int a2, int a3, int a4) {
    return (a1 == this->answer1 &&
            a2 == this->answer2 &&
            a3 == this->answer3 &&
            a4 == this->answer4 );
}

void TZ80::tokenButtonPressed() {
    this->tokenRecieved = true;
    this->widget->getTokenButton()->hide();

    displayAlreadyPassed();
    this->getBackpack()->addItem(new Item(90, "90s Token"));
}

void TZ80::startButtonPressed() {
    this->widget->getStartButton()->hide();
    this->widget->getQuizFrame()->show();
}

void TZ80::closeButtonPressed() {
    this->widget->getStartButton()->show();
    this->widget->getQuizFrame()->hide();
}
