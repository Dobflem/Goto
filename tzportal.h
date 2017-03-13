#include "Timezone.h"
#include "tzportalwidget.h"
#include <QWidget>

#ifndef TZPORTAL_H
#define TZPORTAL_H

class TZPortal: public Timezone
{
public:
    tzportalwidget *widget;
    TZPortal():Timezone("Time-Portal", "portal.jpg", "map.png", "sci-fi.mp3")
    {
        widget = new tzportalwidget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZPORTAL_H
