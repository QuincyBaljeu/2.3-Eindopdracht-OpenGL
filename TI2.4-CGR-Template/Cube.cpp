#include "Cube.h"
#include <iostream>

Cube::Cube(float x, float y, float z)
{
    toMove = false;

    this->x = x;
    this->y = y;
    this->z = z;

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(x, y, z));
    
    angle = 1.0f;
}

Cube::~Cube()
{
}

void Cube::update(double &deltaTime)
{
    if (toMove) 
    {
        this->angle += 0.01f * deltaTime;
    }
    else
    {
        angle = 0.0f;
    }
}

void Cube::draw()
{
    model = glm::rotate(model, angle, glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(model);
    tigl::shader->enableColor(true);
    drawCube();
}

void Cube::toggleMovement() 
{
    this->toMove = !toMove;
}

void Cube::setToMove(bool& toMove)
{
    this->toMove = toMove;
}

float Cube::getX()
{
    return this->x;
}

float Cube::getY()
{
    return this->y;
}

float Cube::getZ()
{
    return this->z;
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
