#include "Timezone.h"

#ifndef TZ80_H
#define TZ80_H


class TZ80 : public Timezone
{
public:
    TZ80(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }
};

#endif // TZ80_H
