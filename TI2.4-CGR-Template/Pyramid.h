#pragma once
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream> 

using tigl::Vertex;

class Pyramid
{
public:
	Pyramid(float, float, float);
	~Pyramid();

	void update(double&);
	void draw();
	void toggleMovement();
	void setToMove(bool&);
	float getX();
	float getY();
	float getZ();

private:
	float x, y, z;
	bool toMove;
	float angle;
	glm::mat4 model;

	void drawPyramid();
};

