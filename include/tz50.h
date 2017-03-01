#include "Timezone.h"
//#include "tz50widget.h"
#include <QWidget>

#ifndef TZ50_H
#define TZ50_H


class TZ50 : public Timezone
{
public:
    //tz50Widget *widget;
    TZ50(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }

    bool canEnterRoom();
   // QWidget* getTimezoneWidget();
};

#endif // TZ50_H
