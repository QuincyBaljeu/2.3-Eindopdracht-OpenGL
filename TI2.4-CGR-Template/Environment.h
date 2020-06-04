#pragma once
#include "tigl.h"
#include "stb_image.h"
#include "Cube.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using tigl::Vertex;

class Environment
{
public:
	Environment();
	~Environment();

	GLuint textureId = -1;
	
	void update();
	void draw();
	void loadFloor();

private:
};

