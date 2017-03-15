#include "backpack.h"
#include <vector>
#include "item.h"

Backpack::Backpack()
{
    this->items = new List<Item>();
}

Backpack::~Backpack() {
    delete this->items;
}

void Backpack::addItem(Item *i) {
    items->add(i);
    // items.push_back(i);
}

Item *Backpack::getItem(int id) {
    for(items->start(); items->currentItem != NULL; items->next()) {
        if (items->currentItem->getID() == id) {
            return items->currentItem;
        }
    } return NULL;
}

bool Backpack::hasItem(int id) {
    for(items->start(); items->currentItem != NULL; items->next()) {
        if (items->currentItem->getID() == id) {
            return true;
        }
    } return false;

    /*
    for(vector<Item>::size_type i = 0; i != items.size(); i++) {
        if(id == items[i].getID()) return true;
    } return false;
    */
}
