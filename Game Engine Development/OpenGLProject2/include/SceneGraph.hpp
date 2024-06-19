// include/SceneGraph.hpp
#pragma once
#include <vector>
#include <memory>
#include <glm/glm.hpp>

class SceneNode {
public:
    SceneNode();
    void addChild(std::shared_ptr<SceneNode> child);
    void removeChild(std::shared_ptr<SceneNode> child);
    void update(const glm::mat4& parentTransform);
    // Add more functions as needed

private:
    std::vector<std::shared_ptr<SceneNode>> children;
    glm::mat4 localTransform;
};

// src/SceneGraph.cpp
#include "SceneGraph.hpp"

SceneNode::SceneNode() : localTransform(glm::mat4(1.0f)) {}

void SceneNode::addChild(std::shared_ptr<SceneNode> child) {
    children.push_back(child);
}

void SceneNode::removeChild(std::shared_ptr<SceneNode> child) {
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

void SceneNode::update(const glm::mat4& parentTransform) {
    glm::mat4 globalTransform = parentTransform * localTransform;
    for (auto& child : children) {
        child->update(globalTransform);
    }
}
