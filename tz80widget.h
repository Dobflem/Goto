#ifndef TZ80WIDGET_H
#define TZ80WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QFrame>

namespace Ui {
class tz80widget;
}

class tz80widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz80widget(QWidget *parent = 0);
    ~tz80widget();

    //Getters for ui elements
    QPushButton* getSubmitButton();
    QPushButton* getUnlockQuestionButton();
    QComboBox* getQ1ComboBox();
    QComboBox* getQ2ComboBox();
    QComboBox* getQ3ComboBox();
    QComboBox* getQ4ComboBox();
    QLabel* getWarningLabel();
    QFrame* getQuizFrame();
    QFrame* getLockedQuestionFrame();
    QPushButton* getTokenButton();
    QPushButton* getStartButton();
    QPushButton* getCloseButton();

private:
    Ui::tz80widget *ui;
};

#endif // TZ80WIDGET_H

