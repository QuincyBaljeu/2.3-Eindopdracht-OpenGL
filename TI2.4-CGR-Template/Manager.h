#pragma once
#include "Cube.h"
#include "Pyramid.h"
#include "ObjModel.h"
#include <GLFW/glfw3.h>

class Manager
{
public:
	Manager();
	~Manager();

	void draw();
	void update();

	void toggleMovement(int);
};

