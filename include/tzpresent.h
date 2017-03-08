#include "Timezone.h"
#include "tzpresentwidget.h"
#include <QWidget>

#ifndef TZPRESENT_H
#define TZPRESENT_H


class TZPresent : public Timezone
{
public:
    tzpresentwidget *widget;
    TZPresent(QString description, QString image):Timezone(description, image)
    {
        widget = new tzpresentwidget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZPRESENT_H
