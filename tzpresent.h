#include "Timezone.h"
#include "tzpresentwidget.h"
#include <QWidget>
#include <QLabel>
#include <QThread>

#ifndef TZPRESENT_H
#define TZPRESENT_H


class TZPresent : public Timezone
{
public:
    tzpresentwidget *widget;
    TZPresent():Timezone("Present Day", "today.jpg", "map-present.png", "creepy-buildup.mp3"),
      widget(new tzpresentwidget()){
    }

    virtual void enter(Backpack* b);
    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();
    virtual void leave();

private:
    void displayInfo();
};

#endif // TZPRESENT_H
