#include "Timezone.h"
#include "tz80widget.h"
#include <QWidget>

#ifndef TZ80_H
#define TZ80_H


class TZ80 : public Timezone
{
public:
    tz80widget *widget;
    TZ80(QString description, QString image, QString mapImage):Timezone(description, image, mapImage)
    {
        widget = new tz80widget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZ80_H
