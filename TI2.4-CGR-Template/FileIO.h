#pragma once
#include <iostream> 
#include <fstream> 
#include <vector> 

#include "Cube.h"

class FileIO
{
public:
	int writeCubesToTxt(std::vector<Cube>&);
	std::vector<Cube> readCubesFromTxt(std::string &);
private:

};

