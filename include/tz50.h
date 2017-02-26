#include "Timezone.h"

#ifndef TZ50_H
#define TZ50_H


class TZ50 : public Timezone
{
public:
    TZ50(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }

    bool canEnterRoom();
};

#endif // TZ50_H
