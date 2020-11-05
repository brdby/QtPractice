#ifndef TREEDRAWER_H
#define TREEDRAWER_H

#include "node.h"

class TreeDrawer
{
public:
    void setNodeCoords(Node &rootNode);
private:
    void calculateInitialX(Node &rootNode);
};

#endif // TREEDRAWER_H
