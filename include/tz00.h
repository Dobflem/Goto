#include "Timezone.h"

#ifndef TZ00_H
#define TZ00_H


class TZ00 : public Timezone
{
public:
    TZ00(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }

    bool canEnterRoom();
};

#endif // TZ00_H
