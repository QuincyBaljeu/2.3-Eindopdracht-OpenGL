#include "FileIO.h"

void FileIO::writeCubesToTxt(std::vector<Cube> &cubes, const std::string& filename)
{
	std::ofstream output;

	output.open(filename);

	for (auto c : cubes)
	{
		//output << d << '\n';
		output << "X: " << c.getX() << " Y: " << c.getY() << " Z: " << c.getZ() << "\n";
	}

	//copy(cubes.begin(), cubes.end(), std::ostream_iterator<int>(output, " "));
	std::cout << "File created" << "\n";
	
	output.close();
}

void FileIO::readCubesFromTxt(const std::string& path)
{
	std::string text;

	std::ifstream input(path);
	if (input.fail()) 
	{
		std::cout << "Failed to open file" << "\n";
		return;
	}

	while (input >> text)
	{
		std::cout << text << "\n";
	}

	return;
}
