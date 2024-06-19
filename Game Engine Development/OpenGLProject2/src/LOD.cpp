#include "LOD.hpp"

void LODModel::addModel(float distance, const std::vector<float>& vertices) {
    lodModels.emplace_back(distance, vertices);
}

const std::vector<float>& LODModel::getLODModel(float distance) const {
    for (const auto& lod : lodModels) {
        if (distance < lod.first) {
            return lod.second;
        }
    }
    return lodModels.back().second;
}
