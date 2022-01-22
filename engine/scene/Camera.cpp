#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp> // translate, rotate, scale, perspective

void Camera::setViewPort(float width, float height)
{
    _viewPort.center = { width * 0.5f, height * 0.5f };
    _viewPort.width = width;
    _viewPort.height = height;
    _viewPort.invertY = true;
}

void Camera::setPerspective(float fov, float aspect, float near, float far)
{
    _fov = glm::radians(fov);
    _aspect = aspect;
    _near = near;
    _far = far;
    _projection = glm::perspective(fov, aspect, near, far);
}

void Camera::setDefaultPerspective()
{
    setPerspective(45.0f, 4.0f / 3.0f, 0.01f, 100.f);
}

Ray Camera::castScreenSpaceRay(uint32_t x, uint32_t y)
{
    if(!_fov || !_aspect || !_near || !_far || !_viewPort.width || !_viewPort.height) {
        return Ray();
    }

    Ray ray;
    ray.origin = position;

    // Define viewing fustrum in camera space.
    // TODO: Transform this into the world coordinate.
    float farPlaneHeight = glm::tan(_fov) * _far * 2.f;
    float farPlaneWidth  = farPlaneHeight * _aspect;
    float u = farPlaneWidth  / _viewPort.width;
    float v = farPlaneHeight / _viewPort.height;

    glm::vec3 target = {
        // x
        (x * u) - (farPlaneWidth * 0.5f),
        // y
        ((_viewPort.height - y) * v) - (farPlaneHeight * 0.5f),
        // z
        -_far
    };
    ray.direction = target - position;

    return ray;
}

void Camera::castScannerRay(uint32_t left, uint32_t top, uint32_t right, uint32_t bottom, std::function<void(const Ray&, uint32_t, uint32_t)> callback)
{
    if (!_fov || !_aspect || !_near || !_far || !_viewPort.width || !_viewPort.height || !callback) {
        return;
    }

    // Define viewing fustrum in camera space.
    // TODO: Transform this into the world coordinate.
    float farPlaneHeight = glm::tan(_fov) * _far * 2.f;
    float farPlaneWidth  = farPlaneHeight * _aspect;
    float u = farPlaneWidth  / _viewPort.width;
    float v = farPlaneHeight / _viewPort.height;

    for (uint32_t row = top; row < bottom; ++row)
    {
        for (uint32_t col = left; col < right; ++col)
        {
            Ray ray;
            ray.origin = position;

            glm::vec3 target = {
                // x
                (col * u) - (farPlaneWidth * 0.5f),
                // y
                ((_viewPort.height - row) * v) - (farPlaneHeight * 0.5f),
                // z
                -_far
            };
            ray.direction = target - position;

            callback(ray, col, row);
        }
    }
}