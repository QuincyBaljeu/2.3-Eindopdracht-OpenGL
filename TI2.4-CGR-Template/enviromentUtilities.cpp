#include "enviromentUtilities.h"

enviromentUtilities::enviromentUtilities()
{
}

enviromentUtilities::~enviromentUtilities()
{
}

void enviromentUtilities::loadFloor()
{
    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PC(glm::vec3(-10, -1, -10), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-10, -1, 10), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(10, -1, 10), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(10, -1, -10), glm::vec4(1, 1, 1, 1)));
    tigl::end();
}
