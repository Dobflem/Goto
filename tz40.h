#include "Timezone.h"
#include "tz40widget.h"
#include <QWidget>
#include <QThread>

#ifndef TZ40_H
#define TZ40_H


class TZ40 : public QThread, public Timezone {
    Q_OBJECT

public:
    tz40widget *widget;
    TZ40():Timezone("Fourties", "fourties.jpg", "map-40s.png", "1940-swing.mp3")
    {
        widget = new tz40widget();
        QObject::connect(widget->getJoint(), SIGNAL(clicked()), this, SLOT(jointButtonPressed()));
    }

    //Virtual
    void enter(Backpack* b);
    bool canEnterRoom(Backpack *b);
    QWidget* getTimezoneWidget();
    void leave();

public slots:
   void jointButtonPressed();
};

#endif // TZ40_H
