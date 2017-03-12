#include "item.h"

Item::Item(int id, QString desc) {
    this->ID = id;
    this->description = desc;
}

int Item::getID() {
    return this->ID;
}
