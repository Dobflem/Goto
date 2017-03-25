#ifndef TZPRESENTWIDGET_H
#define TZPRESENTWIDGET_H

#include <QWidget>
#include <QLabel>


namespace Ui {
class tzpresentwidget;
}

class tzpresentwidget : public QWidget
{
    Q_OBJECT

public:
    explicit tzpresentwidget(QWidget *parent = 0);
    ~tzpresentwidget();

private:
    Ui::tzpresentwidget *ui;

};

#endif // TZPRESENTWIDGET_H
