#include "Pyramid.h"

Pyramid::Pyramid(float, float, float)
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
    drawPyramid();
}

void Pyramid::drawPyramid()
{
    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Right
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Left
    glColor3f(1.0f, 0.0f, 0.0f);       // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);       // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);       // Green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
}
