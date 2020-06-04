#include "Cube.h"

Cube::Cube(int x, int y, int z)
{
    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(x, y, z));
    angle = 0;
}

Cube::~Cube()
{
}

void Cube::update()
{
    angle += 0.1f;
}

void Cube::draw()
{
    model = glm::rotate(model, angle, glm::vec3(1, 0, 0));
    tigl::shader->setModelMatrix(model);
    drawCube();
}

void Cube::drawCube() 
{
    tigl::begin(GL_QUADS);
    //front
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, 0), glm::vec4(-1, 1, 1, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 0), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, 0), glm::vec4(0, 0, 1, 1)));

    //left
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, 0), glm::vec4(-1, 0, 0, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, -1), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, -1), glm::vec4(0, 0, 1, 1)));

    //back
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, -1), glm::vec4(-1, 0, 0, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, -1), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, -1), glm::vec4(0, 0, 1, 1)));

    //right
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, -1), glm::vec4(-1, 0, 0, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 0), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, 0), glm::vec4(0, 0, 1, 1)));

    //top
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(-1, 0, 0, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, -1), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 0), glm::vec4(0, 0, 1, 1)));

    //bottom
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, 0), glm::vec4(-1, 0, 0, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, -1), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, -1), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, 0), glm::vec4(0, 0, 1, 1)));
    tigl::end();
}
