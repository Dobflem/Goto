#include "tz40.h"

bool TZ40::canEnterRoom(Backpack* b) {
    return true;
}

QWidget* TZ40::getTimezoneWidget() {
    cout << "getting 40 widget" << endl;
    return widget;
}

void TZ40::enter(Backpack* b) {
    this->setBackpack(b);
}

void TZ40::leave() {
    qDebug() << "Leaving";
    // Timezone::leave();
}

void TZ40::jointButtonPressed() {
    qDebug() << "Joint pressed";

    this->widget->getJoint()->hide();
    qDebug() << "Joint hidden";

    if (isItemInTimezone(41)) {
        int location = getLocationOfItemInTimezone(41);
        qDebug() << "location:" << location;

        Timezone::getBackpack()->addItem(&itemsInTimezone[location]);
        qDebug() << "Adding item";
        //removeItemFromTimezone(location);
    }
}
