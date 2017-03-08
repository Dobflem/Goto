#include "Timezone.h"
#include "tz30widget.h"
#include <QWidget>

#ifndef TZ30_H
#define TZ30_H


class TZ30 : public Timezone
{
public:
    tz30widget *widget;
    TZ30(QString description, QString image):Timezone(description, image)
    {
        widget = new tz30widget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZ30_H
