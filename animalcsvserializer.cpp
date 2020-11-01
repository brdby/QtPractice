#include "animalcsvserializer.h"

QString AnimalCsvSerializer::toString(const Animal &animal) {
    return QString("%1,%2\n").arg(animal.name).arg(animal.type);
}

Animal AnimalCsvSerializer::fromString(const QString &csvString) {
    auto values = csvString.split(",");
    return {values[0], values[1]};
}
