#include "treedrawer.h"

void TreeDrawer::setNodeCoords(const Node &rootNode)
{
    calculateInitialX(rootNode);
    for (auto &childNode : rootNode.getChildList()) setNodeCoords(childNode);
}

void TreeDrawer::calculateInitialX(const Node &rootNode)
{
    auto childList = rootNode.getChildList();
    for (int i = 0; i < childList.size(); i++) {
        childList[i].setX(i);
    }
}
