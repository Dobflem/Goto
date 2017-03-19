#ifndef BACKPACK_H
#define BACKPACK_H

#include "item.h"
#include "vector"
#include "list.h"
#include "infomessage.h"

class Backpack {
public:
    Backpack();
    ~Backpack();
    void addItem(Item *i);
    Item *getItem(int id);
    bool hasItem(int id);

    InfoMessage* getContents();
    QString contentsString;

private:
    List<Item> *items;
    InfoMessage* contents;
    void setContentsString();
    // vector<Item> items;
};

#endif // BACKPACK_H
