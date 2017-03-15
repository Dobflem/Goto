#ifndef BACKPACK_H
#define BACKPACK_H

#include "item.h"
#include "vector"
#include "list.h"

class Backpack
{
public:
    Backpack();
    ~Backpack();
    void addItem(Item *i);
    Item *getItem(int id);
    bool hasItem(int id);

private:
    List<Item> *items;
    // vector<Item> items;
};

#endif // BACKPACK_H
