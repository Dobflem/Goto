#include "Timezone.h"

#ifndef TZ40_H
#define TZ40_H


class TZ40 : public Timezone
{
public:
    TZ40(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }

    bool canEnterRoom();
};

#endif // TZ40_H
