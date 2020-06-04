#pragma once
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>

using tigl::Vertex;

class Cube
{
public:
	Cube(int,int,int);
	~Cube();

	void update(double&);
	void draw();

private:
	void drawCube();
	float angle = 0.0f;
	glm::mat4 model;
};

