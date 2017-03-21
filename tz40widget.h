#ifndef TZ40WIDGET_H
#define TZ40WIDGET_H

#include <QWidget>
#include <QPushButton>


namespace Ui {
class tz40widget;
}

class tz40widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz40widget(QWidget *parent = 0);
    ~tz40widget();
    QPushButton* getJoint();

private:
    Ui::tz40widget *ui;
};

#endif // TZ40WIDGET_H

