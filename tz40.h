#include "Timezone.h"
#include "tz40widget.h"
#include <QWidget>

#ifndef TZ40_H
#define TZ40_H


class TZ40 : public Timezone
{
public:
    tz40widget *widget;
    TZ40():Timezone("Fourties", "fourties.jpg", "map-40s.png", "1940-swing.mp3")
    {
        widget = new tz40widget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZ40_H
