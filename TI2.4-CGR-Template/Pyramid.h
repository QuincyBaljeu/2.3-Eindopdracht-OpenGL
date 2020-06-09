#pragma once
#include "tigl.h"
#include "Shape.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream> 

using tigl::Vertex;

class Pyramid : public Shape
{
public:
	Pyramid(float, float, float);
	~Pyramid();

	void update(double&) override;
	void draw() override;
	void toggleMovement() override;
	void setToMove(bool&) override;
	float getX() override;
	float getY() override;
	float getZ() override;
private:
	float x, y, z;
	bool toMove;
	float angle;
	glm::mat4 model;

	void drawPyramid();
};

