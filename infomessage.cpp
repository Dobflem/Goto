#include "infomessage.h"

InfoMessage::InfoMessage() {}

QString InfoMessage::getMessage() {
    return this->message;
}

void InfoMessage::setMessage(const QString& msg) {
    this->message = msg;
    emit valueChanged(this->message);
}

