#ifndef TZ40WIDGET_H
#define TZ40WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


class tz40Widget : public QWidget
{
    Q_OBJECT

public:
    tz40Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // TZ40WIDGET_H

