#ifndef TZPRESENTWIDGET_H
#define TZPRESENTWIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


namespace Ui {
class tzpresentwidget;
}

class tzpresentwidget : public QWidget
{
    Q_OBJECT

public:
    explicit tzpresentwidget(QWidget *parent = 0);
    ~tzpresentwidget();
    //void paintEvent(QPaintEvent *event);

private:
    Ui::tzpresentwidget *ui;
};

#endif // TZPRESENTWIDGET_H
