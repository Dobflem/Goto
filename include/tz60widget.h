#ifndef TZ60WIDGET_H
#define TZ60WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


class tz60Widget : public QWidget
{
    Q_OBJECT

public:
    tz60Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // TZ60WIDGET_H
