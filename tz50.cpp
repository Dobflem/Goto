#include "tz50.h"

bool TZ50::canEnterRoom(Backpack *b) {
    return true;
}

QWidget* TZ50::getTimezoneWidget() {
   cout << "getting 50 widget" << endl;
    return widget;
}

void TZ50::enter(Backpack* b) {

}

void TZ50::leave() {
    qDebug() << "Leaving";
    // Timezone::leave();
}

void TZ50::junkFoodButtonPressed() {
    this->widget->getJunkFood()->hide();

    if (isItemInTimezone(51)) {
        int location = getLocationOfItemInTimezone(51);
        Timezone::getBackpack()->addItem(&itemsInTimezone[location]);
        removeItemFromTimezone(location);
    }
}
