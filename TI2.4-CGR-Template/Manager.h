#pragma once
#include "Cube.h"
#include "Pyramid.h"
#include "ObjModel.h"
class Manager
{
public:
	Manager();
	~Manager();

	void draw();
	void update(double&);

	void setToMove(int, bool&);
	void toggleMovement(int);
};

