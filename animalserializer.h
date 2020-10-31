#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "animal.h"

class AnimalSerializer
{
public:
    virtual QString toString(const Animal &animal) = 0;
    virtual Animal fromString(const QString &csvString) = 0;
};

#endif // SERIALIZER_H
