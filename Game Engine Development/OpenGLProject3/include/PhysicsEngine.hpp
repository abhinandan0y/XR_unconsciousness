// include/PhysicsEngine.hpp
#pragma once
#include <btBulletDynamicsCommon.h>

class PhysicsEngine {
public:
    PhysicsEngine();
    ~PhysicsEngine();
    void addRigidBody(btRigidBody* body);
    void simulate(float deltaTime);
    // Add more functions as needed

private:
    btDiscreteDynamicsWorld* dynamicsWorld;
    btBroadphaseInterface* broadphase;
    btDefaultCollisionConfiguration* collisionConfig;
    btCollisionDispatcher* dispatcher;
    btSequentialImpulseConstraintSolver* solver;
};

// src/PhysicsEngine.cpp
#include "PhysicsEngine.hpp"

PhysicsEngine::PhysicsEngine() {
    // Initialize Bullet physics components here
}

PhysicsEngine::~PhysicsEngine() {
    // Cleanup Bullet physics components here
}

void PhysicsEngine::addRigidBody(btRigidBody* body) {
    dynamicsWorld->addRigidBody(body);
}

void PhysicsEngine::simulate(float deltaTime) {
    dynamicsWorld->stepSimulation(deltaTime);
}
