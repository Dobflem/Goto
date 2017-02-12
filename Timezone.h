#ifndef TIMEZONE_H_
#define TIMEZONE_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Timezone {

private:
	string description;
    map<string, Timezone*> exits;
	string exitString();
    vector <Item> itemsInTimezone;


public:
    int numberOfItems();
    Timezone(string description);
    void setExits(Timezone *north, Timezone *east, Timezone *south, Timezone *west);
	string shortDescription();
	string longDescription();
    Timezone* nextTimezone(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int isItemInTimezone(string inString);
    void removeItemFromTimezone(int location);
};

#endif
