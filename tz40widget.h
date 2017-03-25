#ifndef TZ40WIDGET_H
#define TZ40WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QFrame>
#include <vector>


namespace Ui {
class tz40widget;
}

class tz40widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz40widget(QWidget *parent = 0);
    ~tz40widget();
    void toggleGameFrame();

    //getters
    QPushButton* getJoint();
    QPushButton* getSubmitButton();
    QPushButton* getCloseButton();
    QPushButton* getStartButton();
    QPushButton* getTokenButton();
    QSlider* getSlider(int num);
    QFrame* getGameFrame();
    QLabel* getSlinky();
    QLabel* getBarbie();
    QLabel* getBandAid();
    QLabel* getJeep();
    QLabel* getMicrowave();
    QLabel* getWarningLabel();


private:
    Ui::tz40widget *ui;
};

#endif // TZ40WIDGET_H

