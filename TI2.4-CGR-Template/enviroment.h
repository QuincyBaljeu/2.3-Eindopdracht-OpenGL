#pragma once
#include "tigl.h"
#include "stb_image.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>


using tigl::Vertex;

class enviroment
{
public:
	enviroment();
	~enviroment();

	GLuint textureId = -1;
	
	void loadFloor();
	void update(GLFWwindow*);
	void draw();
};

