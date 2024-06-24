#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    glm::vec3 Position, Front, Up;
    float Yaw, Pitch;

    Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
    glm::mat4 GetViewMatrix();
    void ProcessKeyboard(char direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset);
};
