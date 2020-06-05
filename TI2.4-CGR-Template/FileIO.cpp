#include "FileIO.h"

int FileIO::writeCubesToTxt(std::vector<Cube> &cubes, const std::string& filename)
{
	std::ofstream output;

	output.open(filename);

	for (Cube c : cubes)
	{
		output << "X: " << c.getX() << " Y: " << c.getY() << " Z: " << c.getZ();
	}

	copy(cubes.begin(), cubes.end(), std::ostream_iterator<int>(output, " "));
	std::cout << "File created" << "\n";

	return 0;
}

std::vector<Cube> FileIO::readCubesFromTxt(const std::string& path)
{

	std::vector<Cube> cubes;

	return cubes;
}
