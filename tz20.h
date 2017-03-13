#include "Timezone.h"
#include "tz20widget.h"
#include <QWidget>

#ifndef TZ20_H
#define TZ20_H

class TZ20 : public Timezone
{
public:
    tz20widget *widget;
    TZ20():Timezone("Twenties", "twenties.jpg", "map-20s.png", "roaring-20s.mp3")
    {
        widget = new tz20widget();
        // Nothing to do
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZ20_H
