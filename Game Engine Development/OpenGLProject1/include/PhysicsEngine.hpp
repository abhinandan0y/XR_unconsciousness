#pragma once
#include <glm/glm.hpp>

class RigidBody {
public:
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    float mass;

    RigidBody(glm::vec3 pos, float m) : position(pos), mass(m), velocity(0), acceleration(0) {}
    void applyForce(const glm::vec3& force) {
        acceleration += force / mass;
    }
    void update(float deltaTime) {
        velocity += acceleration * deltaTime;
        position += velocity * deltaTime;
        acceleration = glm::vec3(0);  // Reset acceleration after each update
    }
};
