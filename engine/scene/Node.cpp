#include "Node.h"

#include <glm/ext.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/ext/matrix_transform.hpp> // translate, rotate, scale, identity

Node::Node()
{
}

Node::~Node()
{
}

glm::mat4 Node::getTransform() const
{
    glm::mat4 transform;
    transform[3] = glm::vec4(position, 1);
    transform *= glm::mat4_cast(rotation);
    transform  = glm::scale(transform, scale);

    return transform;
}