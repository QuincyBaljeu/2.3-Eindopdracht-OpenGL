#include "Environment.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Cube.h"

Environment::Environment()
{
    glEnable(GL_DEPTH_TEST);

    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    stbi_set_flip_vertically_on_load(true);

    int width, height, comp;
    unsigned char* data = stbi_load("textures/enviromentAtlas.jpg", &width, &height, &comp, 4);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    stbi_image_free(data);
}

Environment::~Environment()
{
}

void Environment::update()
{
}


void Environment::draw()
{
	loadFloor();
	loadWalls();
}

void Environment::loadFloor()
{
    float textureScale = 1 / 4.0f;

    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PT(glm::vec3(-10, -1, -10), glm::vec2(0, 0)));
    tigl::addVertex(Vertex::PT(glm::vec3(-10, -1, 10), glm::vec2(0, -textureScale)));
    tigl::addVertex(Vertex::PT(glm::vec3(10, -1, 10), glm::vec2(textureScale, -textureScale)));
    tigl::addVertex(Vertex::PT(glm::vec3(10, -1, -10), glm::vec2(textureScale, 0)));
    tigl::end();
}

void Environment::loadWalls()
{
	float textureScale = 1 / 4.0f;

    //front
	tigl::begin(GL_QUADS);
	tigl::addVertex(Vertex::PT(glm::vec3(-10, -1, -10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(10, -1, -10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(10, 10, -10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(-10, 10, -10), glm::vec2(0, 0)));
	tigl::end();

    //back
    tigl::begin(GL_QUADS);
	tigl::addVertex(Vertex::PT(glm::vec3(-10, -1, 10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(10, -1, 10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(10, 10, 10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(-10, 10, 10), glm::vec2(0, 0)));
	tigl::end();

	//left
	/*
	tigl::begin(GL_QUADS);
	tigl::addVertex(Vertex::PT(glm::vec3(0, -1, -10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(-10, -1, 10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(10, 10, 10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(-10, 10, 10), glm::vec2(0, 0)));
	tigl::end();
	*/

	//Right
		/*
	tigl::begin(GL_QUADS);
	tigl::addVertex(Vertex::PT(glm::vec3(0, -1, -10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(-10, -1, 10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(10, 10, 10), glm::vec2(0, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(-10, 10, 10), glm::vec2(0, 0)));
	tigl::end();
	*/
}


