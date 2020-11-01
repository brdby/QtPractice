#ifndef ANIMALCSVSERIALIZER_H
#define ANIMALCSVSERIALIZER_H

#include "animalserializer.h"

class AnimalCsvSerializer : public AnimalSerializer
{
public:
    QString toString(const Animal &animal) override;
    Animal fromString(const QString &csvString) override;
};

#endif // ANIMALCSVSERIALIZER_H
