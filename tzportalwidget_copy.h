#ifndef TZPORTALWIDGET_H
#define TZPORTALWIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


class tzPortalWidget : public QWidget
{
    Q_OBJECT

public:
    tzPortalWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // TZPORTALWIDGET_H
