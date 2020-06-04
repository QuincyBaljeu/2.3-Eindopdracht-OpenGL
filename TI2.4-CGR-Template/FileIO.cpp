#include "FileIO.h"

int FileIO::writeCubesToTxt(std::vector<Cube> &cubes)
{
	std::ofstream objectFile;

	objectFile.open("Input.txt", std::ios::app);

	for (Cube c : cubes)
	{
		Cube cubeToWrite(c.getX(), c.getY(), c.getZ());

		objectFile.write((char*)&cubeToWrite, sizeof(cubeToWrite));
	}

	return 0;
}

std::vector<Cube> FileIO::readCubesFromTxt(std::string& path)
{

	std::vector<Cube> cubes;

	return cubes;
}
