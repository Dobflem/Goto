#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <QString>
#include <iostream>
using namespace std;

class Item {
private:
    QString description;
    int ID;

public:
    Item(int id, QString desc);
    int getID();
};

#endif /*ITEM_H_*/
