#ifndef TZ50WIDGET_H
#define TZ50WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


namespace Ui {
class tz50widget;
}

class tz50widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz50widget(QWidget *parent = 0);
    ~tz50widget();
    //void paintEvent(QPaintEvent *event);

private:
    Ui::tz50widget *ui;
};

#endif // TZ50WIDGET_H

