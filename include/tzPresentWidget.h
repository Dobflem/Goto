#ifndef TZPRESENTWIDGET_H
#define TZPRESENTWIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


class tzPresentWidget : public QWidget
{
    Q_OBJECT

public:
    tzPresentWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // TZPRESENTWIDGET_H
