#include "Timezone.h"
#include "tz90widget.h"
#include <QWidget>

#ifndef TZ90_H
#define TZ90_H


class TZ90 : public Timezone
{
public:
    tz90Widget *widget;
    TZ90(QString description, QString image):Timezone(description, image)
    {
        widget = new tz90Widget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZ90_H
