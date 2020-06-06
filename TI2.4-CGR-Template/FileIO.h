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
	void readCubesFromTxt(const std::string&);
private:

};

