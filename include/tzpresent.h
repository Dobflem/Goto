#include "Timezone.h"
//#include "tzPresentWidget.h"
#include <QWidget>

#ifndef TZPRESENT_H
#define TZPRESENT_H


class TZPresent : public Timezone
{
public:
    //tzPresentWidget *widget;
    TZPresent(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }

    bool canEnterRoom();
    //QWidget* getTimezoneWidget();
};

#endif // TZPRESENT_H
