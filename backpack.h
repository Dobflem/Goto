#ifndef BACKPACK_H
#define BACKPACK_H

#include "item.h"
#include "vector"

class Backpack
{
public:
    Backpack();
    void addItem(Item i);
    Item *getItem(int id);
    bool hasItem(int id);

private:
    vector<Item> items;
};

#endif // BACKPACK_H
