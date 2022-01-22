#pragma once

#include <glm/glm.hpp>

/**
 * 2D rectangle.
 * The X coordinate goes from left to right and the Y coordinate goes from
 * bottom to top.
 */
class Rect
{
public:
    glm::vec2 getLeftTop() const;
    glm::vec2 getRightBottom() const;

public:
    glm::vec2 center = {};
    float width = 0;
    float height = 0;
    /// If this flag is raised, the Y coordinate will run from top to bottom instead.
    bool invertY = false;
};