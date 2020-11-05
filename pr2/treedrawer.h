#ifndef TREEDRAWER_H
#define TREEDRAWER_H

#include "node.h"
#include <QHash>

class TreeDrawer
{
public:
    void setNodeCoords(Node &rootNode);
private:
    void calculateInitialX(Node &parent, int initialX);
    QHash <int, int> nodesOnlvl;
};

#endif // TREEDRAWER_H
