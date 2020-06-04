#pragma once
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>

using tigl::Vertex;

class Cube
{
public:
	Cube(float,float,float);
	~Cube();

	void update(double&);
	void draw();
	void toggleMovement();
	void setToMove(bool);
private:
	float x, y, z;
	bool toMove;

	void drawCube();
	float angle = 0.0f;
	glm::mat4 model;
};

