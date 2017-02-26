#include "Timezone.h"

#ifndef TZ70_H
#define TZ70_H


class TZ70 : public Timezone
{
public:
    TZ70(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }

    bool canEnterRoom();
};

#endif // TZ70_H
