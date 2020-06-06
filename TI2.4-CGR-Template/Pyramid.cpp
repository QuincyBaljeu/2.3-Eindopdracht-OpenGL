#include "Pyramid.h"

Pyramid::Pyramid(float x, float y, float z)
{
	toMove = false;

	this->x = x;
	this->y = y;
	this->z = z;

	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(x, y, z));

    angle = 1.0f;
}

Pyramid::~Pyramid()
{
}

void Pyramid::update(double& deltaTime)
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

void Pyramid::draw()
{
    model = glm::rotate(model, angle, glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(model);
	tigl::shader->enableColor(true);
    drawPyramid();
}

void Pyramid::toggleMovement()
{
	this->toMove = !toMove;
}

void Pyramid::setToMove(bool& toMove)
{
	this->toMove = toMove;
}

float Pyramid::getX()
{
	return this->x;
}

float Pyramid::getY()
{
	return this->y;
}

float Pyramid::getZ()
{
	return this->z;
}

void Pyramid::drawPyramid()
{
    tigl::begin(GL_TRIANGLES);          
	tigl::addVertex(Vertex::PC(glm::vec3(-1, 0, -1), glm::vec4(1, 0, 0, 1)));
	tigl::addVertex(Vertex::PC(glm::vec3(1, 0, -1), glm::vec4(0, 1, 0, 1)));
	tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 0, 1, 1)));

	tigl::addVertex(Vertex::PC(glm::vec3(-1, 0, -1), glm::vec4(1, 0, 0, 1)));
	tigl::addVertex(Vertex::PC(glm::vec3(-1, 0, 1), glm::vec4(0, 1, 0, 1)));
	tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 0, 1, 1)));

	tigl::addVertex(Vertex::PC(glm::vec3(1, 0, -1), glm::vec4(1, 0, 0, 1)));
	tigl::addVertex(Vertex::PC(glm::vec3(1, 0, 1), glm::vec4(0, 1, 0, 1)));
	tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 0, 1, 1)));

	tigl::addVertex(Vertex::PC(glm::vec3(1, 0, 1), glm::vec4(1, 0, 0, 1)));
	tigl::addVertex(Vertex::PC(glm::vec3(-1, 0, 1), glm::vec4(0, 1, 0, 1)));
	tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 0, 1, 1)));

	tigl::end();
}
