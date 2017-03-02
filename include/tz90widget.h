#ifndef TZ90WIDGET_H
#define TZ90WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


class tz90Widget : public QWidget
{
    Q_OBJECT

public:
    tz90Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // TZ90WIDGET_H
