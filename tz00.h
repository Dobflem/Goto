#include "Timezone.h"
#include "tz00widget.h"
#include <QWidget>

#ifndef TZ00_H
#define TZ00_H

class TZ00 : public Timezone
{
public:
    tz00widget *widget;
    TZ00():Timezone("Noughties", "noughties.jpg", "map-00s.png", "where-is-the-love.mp3")
    {

        widget = new tz00widget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZ00_H
