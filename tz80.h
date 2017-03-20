#include "Timezone.h"
#include "tz80widget.h"
#include <QWidget>
#include <QObject>
#include <QThread>
#include <unistd.h>
#include <QDebug>

#ifndef TZ80_H
#define TZ80_H


class TZ80 : public QThread, public Timezone {
    Q_OBJECT

private:

    bool tokenRecieved;
    int const answer1;
    int const answer2;
    int const answer3;
    int const answer4;

    void displayInfo();
    void displayAlreadyPassed();
    void showHideLockedQuestion();

public:
    tz80widget *widget;

    TZ80():Timezone("Eighties", "eighties.jpg", "map-80s.png", "take-on-me.mp3"),
        answer1(2), answer2(1), answer3(1), answer4(0) {
        widget = new tz80widget();
        widget->getWarningLabel()->hide();
        this->widget->getTokenButton()->hide();
        this->widget->getQuizFrame()->hide();
        this->widget->getLockedQuestionFrame()->hide();

        tokenRecieved = false;
        QObject::connect(widget->getSubmitButton(), SIGNAL(clicked()), this, SLOT(submitAnswersButtonPressed()));
        QObject::connect(widget->getTokenButton(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));
        QObject::connect(widget->getStartButton(), SIGNAL(clicked()), this, SLOT(startButtonPressed()));
        QObject::connect(widget->getCloseButton(), SIGNAL(clicked()), this, SLOT(closeButtonPressed()));
    }

    //Virtual
    void enter(Backpack* b);
    bool canEnterRoom(Backpack *b);
    QWidget* getTimezoneWidget();
    void leave();

public slots:
   void submitAnswersButtonPressed();
   void tokenButtonPressed();
   void startButtonPressed();
   void closeButtonPressed();

protected:
    void run();
};

#endif // TZ80_H
