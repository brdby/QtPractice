#ifndef TREEDRAWER_H
#define TREEDRAWER_H

#include "node.h"

class TreeDrawer
{
public:
    void setNodeCoords(const Node &rootNode);
private:
    void calculateInitialX(const Node &rootNode);
};

#endif // TREEDRAWER_H
