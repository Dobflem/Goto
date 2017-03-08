#include "Timezone.h"
#include "tz70widget.h"
#include <QWidget>

#ifndef TZ70_H
#define TZ70_H


class TZ70 : public Timezone
{
public:
    tz70widget *widget;
    TZ70(QString description, QString image):Timezone(description, image)
    {
        widget = new tz70widget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZ70_H
