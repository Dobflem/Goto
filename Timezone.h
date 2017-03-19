#include <map>
#include <string>
#include <vector>
#include "item.h"

#ifndef TIMEZONE_H_
#define TIMEZONE_H_

#include <QString>
#include <QDebug>
#include <QWidget>
#include "backpack.h"
#include "infomessage.h"

using namespace std;
using std::vector;

class Timezone {

protected:
    vector<Item> itemsInTimezone;

private:
    QString description;
    QString imagePath;
    QString mapPath;
    QString musicPath;

    map<string, Timezone*> exits;
    Backpack *backpack;
    InfoMessage* infoMessage;

public:
    Timezone(QString description, QString path, QString mapPath, QString musicPath);

    Timezone* getNorthTimezone();
    Timezone* getSouthTimezone();
    Timezone* getEastTimezone();
    Timezone* getWestTimezone();

    void addItem(Item *inItem);
    void removeItemFromTimezone(int location);
    void setExits(Timezone *north, Timezone *east, Timezone *south, Timezone *west);
    bool isItemInTimezone(int itemId);
    int getLocationOfItemInTimezone(int itemId);
    int numberOfItems();


    // GETTERS
    QString getTZImage();
    QString getImagePath();
    QString getMapPath();
    QString getMusicPath();
    QString getDescription();
    InfoMessage* getInfoMessage();
    Backpack* getBackpack();
    vector<Item> getItemsInTimezone();


    // SETTERS
    void setBackpack(Backpack *b);

    // VIRTUAL METHODS
    virtual void enter(Backpack *b) {
        this->setBackpack(b);
    }
    virtual ~Timezone() {
        delete this;
    }
    virtual bool canEnterRoom(Backpack *b) {
        if(b != NULL) {
            return true;
        } else {
            return false;
        }
    }
    virtual QWidget* getTimezoneWidget() {
        cout << "In default get timezone widget" << endl;
        QWidget *def = new QWidget();
        return def;
    }

    virtual void leave() {}
    //virtual QWidget* getTimezoneWidget() = 0;
};

#endif
