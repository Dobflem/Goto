#include "Timezone.h"
#include "tz60widget.h"
#include <QWidget>
#include <QObject>
#include <QThread>

#include <thread>
#include <chrono>
#include <vector>


#ifndef TZ60_H
#define TZ60_H


class TZ60 : public QThread, public Timezone
{
Q_OBJECT
public:
    tz60widget *widget;
    TZ60():Timezone("Sixties", "sixties.png", "map-60s.png", "boots.mp3") {
        widget = new tz60widget();

        this->setup();

        QObject::connect(widget->getTokenButton(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));
        QObject::connect(widget->getStartConvoButton(), SIGNAL(clicked()), this, SLOT(startConvoButtonPressed()));
        QObject::connect(widget->getNextButton(), SIGNAL(clicked()), this, SLOT(nextButtonPressed()));
        QObject::connect(widget->getGiveHippieFoodButton(), SIGNAL(clicked()), this, SLOT(giveHippieFoodButtonPressed()));
        QObject::connect(widget->getGiveHippieJointButton(), SIGNAL(clicked()), this, SLOT(giveHippieJointButtonPressed()));
        QObject::connect(this, SIGNAL(switchHippies()), this->widget, SLOT(swapHippieLabels()));
    }

    //Virtual
    void enter(Backpack* b);
    bool canEnterRoom(Backpack *b);
    QWidget* getTimezoneWidget();
    void leave();

private:
    bool tokenRecieved;
    bool hippieTalking;
    vector<QString> hippieSentences;
    int indexOfCurrentSentence;

    void setup();
    void showHideHaveFoodWarning();
    void showHideHaveJointWarning();
    void displayAlreadyPassed();
    void displayInfo();
    void startTalking();
    void stopTalking();
    void incrementSentence();
    void updateSpeechBubble();

protected:
    void run();

public slots:
   void startConvoButtonPressed();
   void tokenButtonPressed();
   void nextButtonPressed();
   void giveHippieFoodButtonPressed();
   void giveHippieJointButtonPressed();

signals:
    void switchHippies();
};

#endif // TZ60_H
