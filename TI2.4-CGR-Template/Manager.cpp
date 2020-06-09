#include "Manager.h"

//Cubes
Cube cube1(5, -1, 5);
Cube cube2(5, -1, -5);

//Pyramids
Pyramid pyramid1(-5, -1, 5);
Pyramid pyramid2(-5, -1, -5);

//3D model
ObjModel flowerModel("models/bloemetje/PrimroseP.obj", 0, -0.75, 0);

double lastFrameTime;

Manager::Manager()
{
}

Manager::~Manager()
{
}

void Manager::draw()
{
    cube1.draw();
    cube2.draw();

    pyramid1.draw();
    pyramid2.draw();

    flowerModel.draw();
}

void Manager::update()
{
    double currentTime = glfwGetTime();
    double deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    cube1.update(deltaTime);
    cube2.update(deltaTime);

    pyramid1.update(deltaTime);
    pyramid2.update(deltaTime);
}

void Manager::toggleMovement(int shape)
{
    switch (shape)
    {
    case 1:
        cube2.toggleMovement();
        break;
    case 2:
        pyramid2.toggleMovement();
        break;
    default:
        std::cout << "Invalid shape no." << "\n";
        break;
    }
}


