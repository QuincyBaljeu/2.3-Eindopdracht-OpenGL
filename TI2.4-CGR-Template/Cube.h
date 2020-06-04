#pragma once
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>

using tigl::Vertex;

class Cube
{
public:
	Cube(int,int,int);
	~Cube();

	void update();
	void draw();

private:
	void drawCube();
	float angle;
	glm::mat4 model;
};

