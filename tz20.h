#include "Timezone.h"
#include "tz20widget.h"
#include <QWidget>
#include <QObject>
#include <QThread>
#include <unistd.h>
#include <QDebug>
#include "clickablelabel.h"

#ifndef TZ20_H
#define TZ20_H

class TZ20 : public QThread, public Timezone {
    Q_OBJECT

private:
    void displayInfo();
    bool tokenRecieved;
    void displayAlreadyPassed();

public:
    tz20widget *widget;

    TZ20():Timezone("Twenties", "twenties.jpg", "map-20s.png", "roaring-20s.mp3")
    {
        widget = new tz20widget();
        tokenRecieved = false;

        QObject::connect(widget->getButton(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));
    }

    //Virtual
    void enter(Backpack* b);
    bool canEnterRoom(Backpack *b);
    QWidget* getTimezoneWidget();
    void leave();


public slots:
   void tokenButtonPressed();

protected:
    void run();

};

#endif // TZ20_H
