#include "FrustumCulling.hpp"
#include <glm/gtc/matrix_transform.hpp> // For glm::perspective and glm::lookAt

void FrustumCulling::updateFrustum(const glm::mat4& projection, const glm::mat4& view) {
    glm::mat4 clip = projection * view;

    planes[0] = glm::vec4(clip[0][3] - clip[0][0], clip[1][3] - clip[1][0], clip[2][3] - clip[2][0], clip[3][3] - clip[3][0]);
    planes[1] = glm::vec4(clip[0][3] + clip[0][0], clip[1][3] + clip[1][0], clip[2][3] + clip[2][0], clip[3][3] + clip[3][0]);
    planes[2] = glm::vec4(clip[0][3] + clip[0][1], clip[1][3] + clip[1][1], clip[2][3] + clip[2][1], clip[3][3] + clip[3][1]);
    planes[3] = glm::vec4(clip[0][3] - clip[0][1], clip[1][3] - clip[1][1], clip[2][3] - clip[2][1], clip[3][3] - clip[3][1]);
    planes[4] = glm::vec4(clip[0][3] - clip[0][2], clip[1][3] - clip[1][2], clip[2][3] - clip[2][2], clip[3][3] - clip[3][2]);
    planes[5] = glm::vec4(clip[0][3] + clip[0][2], clip[1][3] + clip[1][2], clip[2][3] + clip[2][2], clip[3][3] + clip[3][2]);

    for (int i = 0; i < 6; ++i) {
        float length = glm::length(glm::vec3(planes[i]));
        planes[i] /= length;
    }
}

bool FrustumCulling::isInFrustum(const glm::vec3& point, float radius) const {
    for (int i = 0; i < 6; ++i) {
        if (glm::dot(glm::vec3(planes[i]), point) + planes[i].w + radius < 0)
            return false;
    }
    return true;
}
