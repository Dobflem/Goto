#include "Timezone.h"
#include "tz50widget.h"
#include <QWidget>

#ifndef TZ50_H
#define TZ50_H


class TZ50 : public Timezone
{
public:
    tz50widget *widget;
    TZ50():Timezone("Fifties", "fifties.jpg", "map-50s.png", "jailhouse-rock.mp3")
    {
        widget = new tz50widget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZ50_H
