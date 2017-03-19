#ifndef TZ20WIDGET_H
#define TZ20WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "clickablelabel.h"


namespace Ui {
class tz20widget;
}

class tz20widget : public QWidget
{
    Q_OBJECT
    friend class TZ20;

public:
    explicit tz20widget(QWidget *parent = 0);
    ~tz20widget();
    //void paintEvent(QPaintEvent *event);
    QPushButton* getButton();

private:
    Ui::tz20widget *ui;
};

#endif // TZ20WIDGET_H

