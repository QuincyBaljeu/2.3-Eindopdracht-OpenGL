#pragma once
#include <iostream> 
#include <fstream> 
#include <vector> 
#include <iterator>

#include "Cube.h"

class FileIO
{
public:
	void writeCubesToTxt(std::vector<Cube>&, const std::string&);
	std::vector<Cube> readCubesFromTxt(const std::string&);
private:

};

