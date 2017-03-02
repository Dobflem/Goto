#ifndef TZ50WIDGET_H
#define TZ50WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


class tz50Widget : public QWidget
{
    Q_OBJECT

public:
    tz50Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // TZ50WIDGET_H
