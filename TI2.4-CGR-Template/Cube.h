#pragma once
#include "tigl.h"
#include "Shape.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream> 
#include <fstream> 

using tigl::Vertex;

class Cube : public Shape
{
public:
	Cube(float,float,float);
	~Cube();

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

	void drawCube();
};

