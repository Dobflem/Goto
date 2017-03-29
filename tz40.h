#include "Timezone.h"
#include "tz40widget.h"
#include <QWidget>
#include <QThread>
#include <QTimer>

#ifndef TZ40_H
#define TZ40_H

#define EQUAL(a,b) (((a == b)) ? true : false)


class TZ40 : public QThread, public Timezone {
    Q_OBJECT

public:
    tz40widget *widget;
    TZ40():Timezone("Fourties", "fourties.jpg", "map-40s.png", "1940-swing.mp3"),
      widget(new tz40widget()), answer1(1), answer2(0), answer3(1),
      answer4(2), answer5(1), tokenRecieved(false) {
        this->setup();
    }

    virtual void enter(Backpack* b);
    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();

private:
    const int answer1;
    const int answer2;
    const int answer3;
    const int answer4;
    const int answer5;

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
