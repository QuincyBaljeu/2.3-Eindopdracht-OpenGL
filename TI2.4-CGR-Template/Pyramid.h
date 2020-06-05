#pragma once
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream> 

class Pyramid
{
public:
	Pyramid(float, float, float);
	~Pyramid();

	void update(double&);
	void draw();

private:
	float x, y, z;
	bool toMove;
	float angle;
	glm::mat4 model;

	void drawPyramid();
};

