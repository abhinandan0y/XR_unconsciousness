#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // For glm::perspective and glm::lookAt
#include "FrustumCulling.hpp"
#include "LOD.hpp"
#include "ThreadPool.hpp"

int main() {
    // Example usage of Frustum Culling
    FrustumCulling frustum;
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f/3.0f, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0,0,5), glm::vec3(0,0,0), glm::vec3(0,1,0));
    frustum.updateFrustum(projection, view);

    glm::vec3 point(0, 0, 0);
    if (frustum.isInFrustum(point, 1.0f)) {
        std::cout << "Point is in the frustum.\n";
    } else {
        std::cout << "Point is not in the frustum.\n";
    }

    // Example usage of LOD
    LODModel lodModel;
    lodModel.addModel(10.0f, { /* Low detail vertices */ });
    lodModel.addModel(50.0f, { /* Medium detail vertices */ });
    lodModel.addModel(100.0f, { /* High detail vertices */ });

    float distance = 25.0f;
    const std::vector<float>& model = lodModel.getLODModel(distance);

    // Example usage of ThreadPool
    ThreadPool pool(4);
    pool.enqueue([] { std::cout << "Task 1 executed.\n"; });
    pool.enqueue([] { std::cout << "Task 2 executed.\n"; });
    pool.enqueue([] { std::cout << "Task 3 executed.\n"; });

    return 0;
}
