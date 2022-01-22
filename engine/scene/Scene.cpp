#include "Scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

std::shared_ptr<Node> Scene::addNode()
{
    return _nodeList.emplace_back(std::make_shared<Node>());
}