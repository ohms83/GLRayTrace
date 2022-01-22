#pragma once

#include "Node.h"
#include "geometry/Rect.h"
#include "geometry/Ray.h"

#include <functional>

class Camera : public Node
{
public:
    void setViewPort(float width, float height);
    void setPerspective(float fov, float aspect, float near, float far);
    void setDefaultPerspective();

    const glm::mat4& getProjection() const
    {
        return _projection;
    }

    const Rect& getViewPort() const
    {
        return _viewPort;
    }

    /// Cast a ray from the designated screen-space's <x,y> coordinate.
    Ray castScreenSpaceRay(uint32_t x, uint32_t y);
    /// Shoot scanner rays pixel-by-pixel from left-top to right-bottom.
    void castScannerRay(uint32_t left, uint32_t top, uint32_t right, uint32_t bottom, std::function<void(const Ray&, uint32_t, uint32_t)> callback);

private:
    /// Camera's field-of-view in radian.
    float _fov = 0;
    float _aspect = 0;
    float _near = 0;
    float _far = 0;
    glm::mat4 _projection;
    Rect _viewPort;
};