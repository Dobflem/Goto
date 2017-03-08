#include "Timezone.h"
#include "tzPortalwidget.h"
#include <QWidget>

#ifndef TZPORTAL_H
#define TZPORTAL_H

class TZPortal: public Timezone
{
public:
    tzportalwidget *widget;
    TZPortal(QString description, QString image):Timezone(description, image)
    {
        widget = new tzportalwidget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZPORTAL_H
