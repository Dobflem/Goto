#include "Timezone.h"
#include "tz30widget.h"
#include "clickablelabel.h"

#include <QWidget>
#include <QThread>
#include <QMouseEvent>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QFuture>
#include <QObject>
#include <QtConcurrent/QtConcurrent>
#include <QMouseEvent>

#include <thread>
#include <chrono>

#ifndef TZ30_H
#define TZ30_H


class TZ30 : public QThread, public Timezone  {
Q_OBJECT

public:
    tz30widget *widget;
    TZ30():Timezone("Thirties", "thirties.jpg", "map-30s.png", "roaring-30s.mp3"),
       widget(new tz30widget()), playing(false), score(0) {
        this->setup();
    }

    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();
    virtual void enter(Backpack *b = NULL);
    virtual void leave();

private:
    bool playing;
    int score;
    void startPlaying();
    void stopPlaying();
    void setup();

protected:
    void run();

private slots:
   void caughtCapone();
   void tokenButtonPressed();

signals:
    void caponeXYchanged(int x, int y);
    void caponeToggle();
};

#endif // TZ30_H
