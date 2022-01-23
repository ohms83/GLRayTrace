#include "Scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

std::shared_ptr<Node> Scene::newNode()
{
    return _nodeList.emplace_back(std::make_shared<Node>());
}

void Scene::addNode(std::shared_ptr<Node> node)
{
    _nodeList.emplace_back(node);
}