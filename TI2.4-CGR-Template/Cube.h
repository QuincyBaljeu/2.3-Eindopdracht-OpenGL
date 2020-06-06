#pragma once
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream> 
#include <fstream> 

using tigl::Vertex;

class Cube
{
public:
	Cube(float,float,float);
	~Cube();

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

	void drawCube();
};

