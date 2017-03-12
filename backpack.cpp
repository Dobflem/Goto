#include "backpack.h"
#include <vector>
#include "item.h"

Backpack::Backpack()
{

}

void Backpack::addItem(Item i) {
    items.push_back(i);
}

Item *Backpack::getItem(int id) {
    for(vector<Item>::size_type i = 0; i != items.size(); i++) {
        if(id == items[i].getID()) return &items[i];
    } return NULL;
}

bool Backpack::hasItem(int id) {
    for(vector<Item>::size_type i = 0; i != items.size(); i++) {
        if(id == items[i].getID()) return true;
    } return false;
}
