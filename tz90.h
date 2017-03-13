#include "Timezone.h"
#include "tz90widget.h"
#include <QWidget>

#ifndef TZ90_H
#define TZ90_H


class TZ90 : public Timezone
{
public:
    tz90widget *widget;
    TZ90():Timezone("Nineties", "nineties.jpg", "map-90s.png", "byebyebye.mp3")
    {
        widget = new tz90widget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZ90_H
