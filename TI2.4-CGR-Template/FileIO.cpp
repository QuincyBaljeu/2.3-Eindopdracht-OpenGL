#include "FileIO.h"

void FileIO::writeCubesToTxt(std::vector<int> &cubes, const std::string& filename)
{
	std::ofstream output;

	output.open(filename);

	for (auto d : cubes)
	{
		output << d << '\n';
		//output << "X: " << c.getX() << " Y: " << c.getY() << " Z: " << c.getZ();
	}

	//copy(cubes.begin(), cubes.end(), std::ostream_iterator<int>(output, " "));
	std::cout << "File created" << "\n";
	
	output.close();
}

std::vector<Cube> FileIO::readCubesFromTxt(const std::string& path)
{

	std::vector<Cube> cubes;

	return cubes;
}
