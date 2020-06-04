#pragma once
#include "tigl.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using tigl::Vertex;

class enviromentUtilities
{
public:
	enviromentUtilities();
	~enviromentUtilities();

	void loadFloor();
};

