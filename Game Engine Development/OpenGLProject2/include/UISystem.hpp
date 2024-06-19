// include/UISystem.hpp
#pragma once
#include "imgui.h"

class UISystem {
public:
    UISystem();
    ~UISystem();
    void render();
};

// src/UISystem.cpp
#include "UISystem.hpp"

UISystem::UISystem() {
    // Initialize ImGui here
}

UISystem::~UISystem() {
    // Cleanup ImGui here
}

void UISystem::render() {
    ImGui::NewFrame();
    // Render UI elements here
    ImGui::Render();
}
