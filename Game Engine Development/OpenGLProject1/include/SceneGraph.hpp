#pragma once
#include <vector>
#include <memory>
#include <glm/glm.hpp>

class SceneNode {
public:
    glm::mat4 transform;
    std::vector<std::shared_ptr<SceneNode>> children;

    SceneNode() : transform(glm::mat4(1.0f)) {}
    void addChild(std::shared_ptr<SceneNode> child) {
        children.push_back(child);
    }
    void traverse(const glm::mat4& parentTransform = glm::mat4(1.0f));
};

void SceneNode::traverse(const glm::mat4& parentTransform) {
    glm::mat4 currentTransform = parentTransform * transform;
    for (auto& child : children) {
        child->traverse(currentTransform);
    }
}
