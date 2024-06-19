#pragma once
#include <vector>
#include <glm/glm.hpp>

class LODModel {
public:
    void addModel(float distance, const std::vector<float>& vertices);
    const std::vector<float>& getLODModel(float distance) const;

private:
    std::vector<std::pair<float, std::vector<float>>> lodModels;
};
