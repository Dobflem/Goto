#include "Timezone.h"
#include "tz00widget.h"
#include <QWidget>
#include <QObject>
#include <QTimer>

#ifndef TZ00_H
#define TZ00_H

class TZ00 : public QObject, public Timezone
{
    Q_OBJECT

private:

public:
    tz00widget *widget;
    TZ00():Timezone("Noughties", "noughties.jpg", "map-00s.png", "where-is-the-love.mp3")
    {
        widget = new tz00widget();
        tokenRecieved = false;
        QObject::connect(widget->getSubmitButton(), SIGNAL(clicked()), this, SLOT(submitButtonPressed()));
        QObject::connect(widget->getTokenButton(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));
    }

    //Virtual
    void enter(Backpack* b);
    bool canEnterRoom(Backpack *b);
    QWidget* getTimezoneWidget();
    void leave();

private:
    bool tokenRecieved;
    void displayAlreadyPassed();
    bool answersCorrect();
    void displayInfo();

public slots:
    void tokenButtonPressed();
    void submitButtonPressed();
};

#endif // TZ00_H
