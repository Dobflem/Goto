#include "Timezone.h"
#include "tz60widget.h"

#include <QWidget>
#include <QObject>
#include <QThread>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QMouseEvent>

#include <thread>
#include <chrono>
#include <vector>

#ifndef TZ60_H
#define TZ60_H

class TZ60 : public QThread, public Timezone {
Q_OBJECT

public:
    tz60widget *widget;
    TZ60():Timezone("Sixties", "sixties.png", "map-60s.png", "boots.mp3"),
    widget(new tz60widget()), tokenRecieved(false),
    hippieTalking(true), indexOfCurrentSentence(0),
    ID_OF_JOINT(41), ID_OF_FOOD(51){
        this->setup();
    }

    virtual void enter(Backpack* b);
    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();
    virtual void leave();

private:
    bool tokenRecieved;
    bool hippieTalking;
    vector<QString> hippieSentences;
    unsigned int indexOfCurrentSentence;
    const int ID_OF_JOINT;
    const int ID_OF_FOOD;

    void setup();
    void setupSignalsAndSlotsConnections();
    void setupHidingUIElements();
    void setupHippieSentences();
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
