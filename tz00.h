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
    TZ00():Timezone("Noughties", "noughties.jpg", "map-00s.png", "where-is-the-love.mp3") {
        this->setup();
    }

    virtual void enter(Backpack* b);
    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();
    virtual void leave();

private:
    bool tokenRecieved;

    void setup();
    void displayAlreadyPassed();
    bool answersCorrect();
    void displayInfo();

public slots:
    void tokenButtonPressed();
    void submitButtonPressed();
};

#endif // TZ00_H
