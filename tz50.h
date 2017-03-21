#include "Timezone.h"
#include "tz50widget.h"
#include <QWidget>
#include <QObject>
#include <QThread>

#ifndef TZ50_H
#define TZ50_H


class TZ50 : public QThread, public Timezone {
    Q_OBJECT

public:
    tz50widget *widget;
    TZ50():Timezone("Fifties", "fifties.jpg", "map-50s.png", "jailhouse-rock.mp3")
    {
        widget = new tz50widget();
        QObject::connect(widget->getJunkFood(), SIGNAL(clicked()), this, SLOT(junkFoodButtonPressed()));
    }

    //Virtual
    void enter(Backpack* b);
    bool canEnterRoom(Backpack *b);
    QWidget* getTimezoneWidget();
    void leave();

public slots:
   void junkFoodButtonPressed();
};

#endif // TZ50_H
