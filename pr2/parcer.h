#ifndef PARCER_H
#define PARCER_H

#include <QList>
#include <QFile>
#include <node.h>

class Parcer
{
public:
    virtual QList<Node> getNodes(QFile &file) = 0;
};

#endif // PARCER_H
