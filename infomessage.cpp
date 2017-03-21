#include "infomessage.h"

InfoMessage::InfoMessage(QWidget *parent) {}

QString InfoMessage::getMessage() {
    return this->message;
}

void InfoMessage::setMessage(QString msg) {
    this->message = msg;
    emit valueChanged(this->message);
}

