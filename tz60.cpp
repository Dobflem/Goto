#include "tz60.h"

#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QMouseEvent>

bool TZ60::canEnterRoom(Backpack* b) {
    return (b->hasItem(60));
}

QWidget* TZ60::getTimezoneWidget() {
    cout << "Getting 60s widget" << endl;
    return widget;
}

void TZ60::enter(Backpack *b) {
    this->setBackpack(b);
    showHideHaveFoodWarning();
    showHideHaveJointWarning();
    this->displayInfo();
}

void TZ60::leave() {
    qDebug() << "leaving";
    this->stopTalking();
}

void TZ60::displayInfo() {
    if (this->tokenRecieved) {
        displayAlreadyPassed();
    } else {
        Timezone::getInfoMessage()->setMessage("Welcome to the groovy 60s. Talk to the hippy to see if you can pass this level");
    }
}

void TZ60::displayAlreadyPassed() {
    Timezone::getInfoMessage()->setMessage("Congratulations. You have passed the 60s level");
}

void TZ60::showHideHaveFoodWarning() {
    if (this->getBackpack()->hasItem(51)) {
        qDebug() << "hiding no food warning";
        this->widget->hideNoFoodWarning();
    } else {
        qDebug() << "showing no food warning";
        this->widget->showNoFoodWarning();
    }
}

void TZ60::showHideHaveJointWarning() {
    if (this->getBackpack()->hasItem(41)) {
        qDebug() << "hiding no joint warning";
        this->widget->hideNoJointWarning();
    } else {
        qDebug() << "showing no joint warning";
        this->widget->showNoJointWarning();
    }
}

void TZ60::run() {
    qDebug() << "running";

    while(this->hippieTalking) {
        emit switchHippies();
        this_thread::sleep_for(chrono::milliseconds(500));
        emit switchHippies();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void TZ60::setup() {
    widget = new tz60widget();
    tokenRecieved = false;
    hippieTalking = true;
    indexOfCurrentSentence = 0;

    setupSignalsAndSlotsConnections();
    setupHidingUIElements();
    setupHippieSentences();
}

void TZ60::setupSignalsAndSlotsConnections() {
    QObject::connect(widget->getTokenButton(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));
    QObject::connect(widget->getStartConvoButton(), SIGNAL(clicked()), this, SLOT(startConvoButtonPressed()));
    QObject::connect(widget->getNextButton(), SIGNAL(clicked()), this, SLOT(nextButtonPressed()));
    QObject::connect(widget->getGiveHippieFoodButton(), SIGNAL(clicked()), this, SLOT(giveHippieFoodButtonPressed()));
    QObject::connect(widget->getGiveHippieJointButton(), SIGNAL(clicked()), this, SLOT(giveHippieJointButtonPressed()));
    QObject::connect(this, SIGNAL(switchHippies()), this->widget, SLOT(swapHippieLabels()));
}

void TZ60::setupHidingUIElements() {
    this->widget->hideSpeechBubble();
    this->widget->hideFoodOptions();
    this->widget->hideJointOptions();
    this->widget->getTokenButton()->hide();
}

void TZ60::setupHippieSentences() {
    hippieSentences.push_back("Hey Man!");
    hippieSentences.push_back("I think I can help you out to get your 70s token. But first ...");
    hippieSentences.push_back("I've got some serious munchies dude.\n Any chance you have any food I can eat?");
    hippieSentences.push_back("Far out man. \nThat burger changed my life! \nI'm ready to make love not war");
    hippieSentences.push_back("You're groovy.\n We should go on a journey together man \n.... you got some of that good stuff?");
    hippieSentences.push_back("Right on man! Power to the people. \nHere's your token...");
}

void TZ60::startTalking() {
    this->hippieTalking = true;
    this->start();
}

void TZ60::stopTalking() {
    this->hippieTalking = false;
}

void TZ60::startConvoButtonPressed() {
    this->widget->getStartConvoButton()->hide();
    this->startTalking();
    this->widget->showSpeechBubble();
    this->widget->setSpeechBubbleText(hippieSentences[this->indexOfCurrentSentence]);
}

void TZ60::nextButtonPressed() {
    if (!this->hippieTalking) {
        this->startTalking();
    }

    incrementSentence();
    if (this->indexOfCurrentSentence < this->hippieSentences.size()) {
        switch (this->indexOfCurrentSentence) {
        case 2:
            updateSpeechBubble();
            this->widget->hideNextArrow();
            this->widget->showFoodOptions();
            break;
        case 4:
            updateSpeechBubble();
            this->widget->hideNextArrow();
            this->widget->showJointOptions();
            break;
        case 5:
            updateSpeechBubble();
            this->stopTalking();
            this->widget->hideNextArrow();
        default:
            this->widget->showNextArrow();
            updateSpeechBubble();
            break;
        }
    } else {
        this->widget->hideNextArrow();
        this->widget->getTokenButton()->show();
        this->widget->hideSpeechBubble();
        this->stopTalking();
    }
}

void TZ60::giveHippieFoodButtonPressed() {
    //TODO: remove from backpack
    //Timezone::getBackpack()->removeItem(51);

    this->widget->hideFoodOptions();
    this->widget->showNextArrow();
    nextButtonPressed();
}

void TZ60::giveHippieJointButtonPressed() {
    //TODO: remove from backpack
    //Timezone::getBackpack()->removeItem(41);

    this->widget->hideJointOptions();
    nextButtonPressed();
}

void TZ60::tokenButtonPressed() {
    this->tokenRecieved = true;
    this->widget->getTokenButton()->hide();

    this->getBackpack()->addItem(new Item(70, "70s Token"));
    displayAlreadyPassed();
}

void TZ60::incrementSentence() {
    this->indexOfCurrentSentence++;
}

void TZ60::updateSpeechBubble() {
    this->widget->setSpeechBubbleText(hippieSentences[this->indexOfCurrentSentence]);
}


