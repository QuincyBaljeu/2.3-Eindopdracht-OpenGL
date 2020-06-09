//header files
#include "tigl.h"
#include "FpsCam.h"
#include "Environment.h"
#include "Cube.h"
#include "Pyramid.h"
#include "FileIO.h"
#include "ObjModel.h"
#include "Manager.h"

//lib files
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>;

//misc.
using tigl::Vertex;

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

//prototypes
void init();
void update();
void draw();
void keyCallBack(GLFWwindow*, int, int, int, int);

//Attributes
GLFWwindow* window;
double lastFrameTime;
FpsCam* camera;
Manager manager;

int main(void)
{
    if (!glfwInit())
        throw "Could not initialize glwf";
    window = glfwCreateWindow(1400, 800, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw "Could not initialize glwf";
    }
    glfwMakeContextCurrent(window);

    tigl::init();

    init();

	while (!glfwWindowShouldClose(window))
	{
		update();
		draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();


    return 0;
}

void init()
{
    glfwSetKeyCallback(window, keyCallBack);

    camera = new FpsCam(window);

    FileIO fileio;
    std::vector<Cube> cubes;
    std::vector<Shape> shapes;

    /*
    shapes.push_back(cube1);
    shapes.push_back(pyramid1);

    cubes.push_back(cube1);
    cubes.push_back(cube2);
    fileio.writeCubesToTxt(cubes, "test2.txt");

    fileio.readCubesFromTxt("test2.txt");
    */
}

void update()
{

    double currentTime = glfwGetTime();
    double deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;
    
    camera->update(window); 
    
    manager.update(deltaTime);
    
    /*
    cube1.update(deltaTime);
    cube2.update(deltaTime);

    pyramid1.update(deltaTime);
    pyramid2.update(deltaTime);
    */

}

void draw()
{
    //settings
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 100.0f);

    tigl::shader->setProjectionMatrix(projection);
    tigl::shader->setViewMatrix(camera->getMatrix());
    tigl::shader->setModelMatrix(glm::mat4(1.0f));

    //Fog settings
    tigl::shader->enableFog(true);
    tigl::shader->setFogLinear(4,10);

    //lighting settings
    tigl::shader->enableLighting(true);
    tigl::shader->setLightCount(1);

    tigl::shader->setLightDirectional(0, false);
    tigl::shader->setLightPosition(0, glm::vec3(0, 3, 0));
    tigl::shader->setLightAmbient(0, glm::vec3(0.1f, 0.1f, 0.15f));
    tigl::shader->setLightDiffuse(0, glm::vec3(0.8f, 0.8f, 0.8f));
    tigl::shader->setLightSpecular(0, glm::vec3(0, 0, 0));
    tigl::shader->setShinyness(32.0f);

    //tigl::shader->enableColor(true);
    tigl::shader->enableTexture(true);
    glEnable(GL_DEPTH_TEST);

    //Environment
    Environment environment;
    environment.draw();

    

    manager.draw();
    /*
    //Cubes
    bool cube1Movement = true;
    cube1.setToMove(cube1Movement);
    cube1.draw();

    cube2.draw();
    
    //Pyramids
    bool pyramid1Movement = true;
    pyramid1.setToMove(pyramid1Movement);
    pyramid1.draw();
    pyramid2.draw();
 
    //3D model
    flowerModel->draw();
    */
}

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE)
    {
        glfwSetWindowShouldClose(window, true);
    }
    else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) 
    {
        manager.toggleMovement(1);
    }
    else if (key == GLFW_KEY_0 && action == GLFW_PRESS) 
    {
        manager.toggleMovement(2);
    }
}



