#include "Timezone.h"
#include "tz90widget.h"
#include <QWidget>
#include <QObject>

#ifndef TZ90_H
#define TZ90_H


class TZ90 : public QObject, public Timezone
{
Q_OBJECT
public:
    tz90widget *widget;
    TZ90():Timezone("Nineties", "nineties.jpg", "map-90s.png", "byebyebye.mp3"),
     widget(new tz90widget()){
        this->setupSignalsAndSlots();
    }

    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();

public slots:
    void transparentTokenClicked();
    void clickedToken();

private:
    void setupSignalsAndSlots();
};

#endif // TZ90_H
