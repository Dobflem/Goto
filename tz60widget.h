#ifndef TZ60WIDGET_H
#define TZ60WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


namespace Ui {
class tz60widget;
}

class tz60widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz60widget(QWidget *parent = 0);
    ~tz60widget();
    //void paintEvent(QPaintEvent *event);

private slots:


private:
    Ui::tz60widget *ui;
};

#endif // TZ60WIDGET_H

