#ifndef TZPORTALWIDGET_H
#define TZPORTALWIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


namespace Ui {
class tzportalwidget;
}

class tzportalwidget : public QWidget
{
    Q_OBJECT

public:
    explicit tzportalwidget(QWidget *parent = 0);
    ~tzportalwidget();
    //void paintEvent(QPaintEvent *event);

private:
    Ui::tzportalwidget *ui;
};

#endif // TZPORTALWIDGET_H

