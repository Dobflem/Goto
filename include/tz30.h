#include "Timezone.h"
//#include "tz30widget.h"
#include <QWidget>

#ifndef TZ30_H
#define TZ30_H


class TZ30 : public Timezone
{
public:
    //tz30Widget *widget;
    TZ30(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }

    bool canEnterRoom();
    //QWidget* getTimezoneWidget();
};

#endif // TZ30_H
