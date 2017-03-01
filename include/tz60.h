#include "Timezone.h"
//#include "tz60widget.h"
#include <QWidget>

#ifndef TZ60_H
#define TZ60_H


class TZ60 : public Timezone
{
public:
    //tz60Widget *widget;
    TZ60(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }

    bool canEnterRoom();
    //QWidget* getTimezoneWidget();
};

#endif // TZ60_H
