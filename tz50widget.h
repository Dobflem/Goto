#ifndef TZ50WIDGET_H
#define TZ50WIDGET_H

#include <QWidget>
#include <QPushButton>


namespace Ui {
class tz50widget;
}

class tz50widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz50widget(QWidget *parent = 0);
    ~tz50widget();
    QPushButton* getJunkFood();

private:
    Ui::tz50widget *ui;
};

#endif // TZ50WIDGET_H

