#include "Timezone.h"
#include "tz80widget.h"
#include <QWidget>
#include <QObject>
#include <unistd.h>
#include <QDebug>

#ifndef TZ80_H
#define TZ80_H


class TZ80 : public QObject, public Timezone {
    Q_OBJECT

private:
    bool tokenRecieved;
    int const answer1;
    int const answer2;
    int const answer3;
    int const answer4;

    void setup();
    void setupHideUIElements();
    void setupSignalsAndSlotConnections();
    void displayInfo();
    void displayAlreadyPassed();
    void showHideLockedQuestion();
    bool allAnswersCorrect(int a1, int a2, int a3, int a4);

public:
    tz80widget *widget;

    TZ80():Timezone("Eighties", "eighties.jpg", "map-80s.png", "take-on-me.mp3"),
        answer1(2), answer2(1), answer3(1), answer4(0) {
         setup();
    }

    virtual void enter(Backpack* b);
    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();
    virtual void leave();

public slots:
   void submitAnswersButtonPressed();
   void tokenButtonPressed();
   void startButtonPressed();
   void closeButtonPressed();
};

#endif // TZ80_H
