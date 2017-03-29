#include "Timezone.h"
#include "tz80widget.h"

#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <unistd.h>

#ifndef TZ80_H
#define TZ80_H

#define EQUAL(a,b) (((a == b)) ? true : false)


class TZ80 : public QObject, public Timezone {
    Q_OBJECT

private:
    bool tokenRecieved;
    int const answer1;
    int const answer2;
    int const answer3;
    int const answer4;
    int const ID_OF_KEY;

    void setup();
    void setupHideUIElements();
    void setupSignalsAndSlotConnections();
    void displayInfo();
    void displayAlreadyPassed();
    void showHideUnlockQuestionButton();
    bool allAnswersCorrect(int a1, int a2, int a3, int a4);

public:
    tz80widget *widget;

    TZ80():Timezone("Eighties", "eighties.jpg", "map-80s.png", "take-on-me.mp3"),
        tokenRecieved(false), answer1(2), answer2(1), answer3(1), answer4(0),ID_OF_KEY(21), widget(new tz80widget())  {
         setup();
    }

    virtual void enter(Backpack* b);
    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();

public slots:
   void submitAnswersButtonPressed();
   void tokenButtonPressed();
   void startButtonPressed();
   void closeButtonPressed();
   void unlockQuestionButtonPressed();
};

#endif // TZ80_H
