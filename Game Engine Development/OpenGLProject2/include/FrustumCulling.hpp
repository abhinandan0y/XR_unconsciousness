#pragma once
#include <glm/glm.hpp>

class FrustumCulling {
public:
    void updateFrustum(const glm::mat4& projection, const glm::mat4& view);
    bool isInFrustum(const glm::vec3& point, float radius) const;

private:
    glm::vec4 planes[6];
};
