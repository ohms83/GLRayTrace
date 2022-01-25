#include "Rect.h"

glm::vec2 Rect::leftTop() const
{
    float signY = (invertY ? -1.f : 1.f);
    glm::vec2 leftTop = { (float)center.x - (float)width * 0.5f, (float)center.y + (float)height * 0.5f * signY };
    return leftTop;
}

glm::vec2 Rect::rightBottom() const
{
    float signY = (invertY ? -1.f : 1.f);
    glm::vec2 rightBottom = { (float)center.x + (float)width * 0.5f, (float)center.y - (float)height * 0.5f * signY };
    return rightBottom;
}