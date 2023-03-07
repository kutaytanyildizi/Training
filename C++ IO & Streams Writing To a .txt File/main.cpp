#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main()
{
    std::ifstream inFile("RomeoAndJuliet.txt");
	std::ofstream outFile("RomeoAndJulietWithLineNumbers.txt");
	if (!outFile)
	{
		std::cerr << "Error when creating file." << std::endl;
		return 1;
	}
    if(!inFile)
    {
        std::cerr << "Error when creating file." << std::endl;
		return 1;
    }

	std::string line{};
    int lineCounter = 1;
    while(!inFile.eof())
    {
        std::getline(inFile, line);
        if(!line.empty())
        {
            outFile << std::setw(7) << std::left << lineCounter << line << std::endl; 
            lineCounter++;
        }
        outFile << std::setw(7) << " " << line << std::endl; 
    }

	outFile.close();
    inFile.close();

	return 0;
}