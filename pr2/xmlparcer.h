#ifndef XMLPARCER_H
#define XMLPARCER_H

#include "parcer.h"

class XMLParcer : public Parcer
{
public:
    QList<Node> getNodes(QFile &file);
};

#endif // XMLPARCER_H
