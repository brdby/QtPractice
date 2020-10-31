#ifndef ANIMALCSVSERIALIZER_H
#define ANIMALCSVSERIALIZER_H

#include "animalserializer.h"

class AnimalCsvSerializer : public AnimalSerializer
{
public:
    virtual QString toString(const Animal &animal);
    virtual Animal fromString(const QString &csvString);
};

#endif // ANIMALCSVSERIALIZER_H
