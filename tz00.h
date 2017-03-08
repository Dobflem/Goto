#include "Timezone.h"
#include "tz00widget.h"
#include <QWidget>

#ifndef TZ00_H
#define TZ00_H

class TZ00 : public Timezone
{
public:
    tz00widget *widget;
    TZ00(QString description, QString image, QString mapImage):Timezone(description, image, mapImage)
    {
        widget = new tz00widget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZ00_H
