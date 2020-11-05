#include "treedrawer.h"

void TreeDrawer::setNodeCoords(Node &rootNode)
{
    calculateInitialX(rootNode);
    for (auto &childNode : rootNode.childList)
        setNodeCoords(childNode);
}

void TreeDrawer::calculateInitialX(Node &rootNode)
{
    for (int i = 0; i < rootNode.childList.size(); i++) {
        rootNode.childList[i].setX(i);
    }
}
