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
    TZ40():Timezone("Fourties", "fourties.jpg", "map-40s.png", "1940-swing.mp3") {
        this->setup();
    }

    virtual void enter(Backpack* b);
    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();
    virtual void leave();

private:
    bool tokenRecieved;
    void setup();
    void changeLabelGeometry(QLabel*, int);
    void displayInfo();
    void displayAlreadyPassed();
    int getImageXValue(int);
    bool sliderAnswersCorrect();

public slots:
   void jointButtonPressed();
   void submitButtonPressed();
   void startButtonPressed();
   void closeButtonPressed();
   void tokenButtonPressed();
   void slinkySliderValueChanged(int);
   void barbieSliderValueChanged(int);
   void jeepSliderValueChanged(int);
   void bandAidSliderValueChanged(int);
   void microwaveSliderValueChanged(int);
};

#endif // TZ40_H
