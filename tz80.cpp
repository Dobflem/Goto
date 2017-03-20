#include "tz80.h"
#include <QTimer>

bool TZ80::canEnterRoom(Backpack *b) {
    //return (b->hasItem(80));
    return true;
}

QWidget* TZ80::getTimezoneWidget() {
    return widget;
}

void TZ80::enter(Backpack *b) {
    this->setBackpack(b);
    this->displayInfo();

    showHideLockedQuestion();
}

void TZ80::run() {
    qDebug() << "running";
}

void TZ80::showHideLockedQuestion() {
    if (this->getBackpack()->hasItem(81)) {
        qDebug() << "hiding locked panel";
        this->widget->getLockedQuestionFrame()->hide();
    } else {
        qDebug() << "showing locked panel";
        this->widget->getLockedQuestionFrame()->show();
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

void TZ80::leave() {
    qDebug() << "Leaving";
    // Timezone::leave();
}

void TZ80::submitAnswersButtonPressed() {
    qDebug() << "Submit answers button pressed";

    int answer1Index = this->widget->getQ1ComboBox()->currentIndex();
    int answer2Index = this->widget->getQ2ComboBox()->currentIndex();
    int answer3Index = this->widget->getQ3ComboBox()->currentIndex();
    int answer4Index = this->widget->getQ4ComboBox()->currentIndex();

    if (answer1Index == this->answer1 &&
        answer2Index == this->answer2 &&
        answer3Index == this->answer3 &&
        answer4Index == this->answer4 ) {
        qDebug() << "All answers correct";

        this->widget->getQuizFrame()->hide();
        this->widget->getTokenButton()->show();

        Timezone::getInfoMessage()->setMessage("Congratulations. You have answered all questions correctly. Select your 90s timezon token to put it in your backpack");
    } else {
        qDebug() << "Incorrect";
        this->widget->getWarningLabel()->show();
        QTimer::singleShot(5000, this->widget->getWarningLabel(), &QLabel::hide);
    }
}

void TZ80::tokenButtonPressed() {
    this->tokenRecieved = true;
    this->widget->getTokenButton()->hide();

    displayAlreadyPassed();

    if (isItemInTimezone(90)) {
        int location = getLocationOfItemInTimezone(90);
        Timezone::getBackpack()->addItem(&itemsInTimezone[location]);
        removeItemFromTimezone(location);
    }
}

void TZ80::startButtonPressed() {
    this->widget->getStartButton()->hide();
    this->widget->getQuizFrame()->show();
}

void TZ80::closeButtonPressed() {
    this->widget->getStartButton()->show();
    this->widget->getQuizFrame()->hide();
}
