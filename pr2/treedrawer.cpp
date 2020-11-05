#include "treedrawer.h"

void TreeDrawer::setNodeCoords(Node &rootNode)
{
    calculateInitialX(rootNode, 0);
}

void TreeDrawer::calculateInitialX(Node &node, int lvl)
{
    for (auto &childNode : node.childList) {
        calculateInitialX(childNode, lvl+1);
    }
    int nodesOnCurrentLvl = nodesOnlvl.value(lvl, 0);
    node.setX(nodesOnCurrentLvl++);
    nodesOnlvl.insert(lvl, nodesOnCurrentLvl);
}
