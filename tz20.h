#include "Timezone.h"
#include "tz20widget.h"
#include "clickablelabel.h"
#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>

#ifndef TZ20_H
#define TZ20_H

class TZ20 : public QObject, public Timezone {
    Q_OBJECT

private:
    bool tokenRecieved;
    void displayAlreadyPassed();
    void displayInfo();
    void setup();

public:
    tz20widget *widget;

    TZ20():Timezone("Twenties", "twenties.jpg", "map-20s.png", "roaring-20s.mp3"),
        tokenRecieved(false), widget(new tz20widget()) {
        this->setup();
    }

    virtual void enter(Backpack* b);
    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();
    virtual void leave();

public slots:
   void tokenButtonPressed();
   void keyButtonPressed();

};

#endif // TZ20_H
