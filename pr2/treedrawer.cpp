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
    int nodesOnCurrentLvl = nodesOnlvl.value(lvl);
    int nodesOnLastLvl = nodesOnlvl.value(lvl-1);
    int acceptedX = nodesOnCurrentLvl>nodesOnLastLvl ? nodesOnCurrentLvl : nodesOnLastLvl;
    node.setX(acceptedX++);
    nodesOnlvl.insert(lvl, acceptedX);
}
