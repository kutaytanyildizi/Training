#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main()
{
	std::ifstream inFile;
	std::string name{};
	std::string answerKey{};
	std::string studentAnswers{};
	int studentGrade{0};
	int sumOfGrades{0};
	int totalStudents{0};
	double averageScore{0.0};
	inFile.open("test.txt");
	std::cout << std::endl;
	std::cout << std::setw(18) << std::left << "Student" << "Score" << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << "-" << std::endl;
	std::cout << std::setfill(' ');
	if (inFile)
	{
		inFile >> answerKey;
		while (!inFile.eof())
		{
			studentGrade = 0;
			inFile >> name;
			std::cout << std::setw(20) << std::left << name;
			totalStudents++;
			inFile >> studentAnswers;
			for (int i = 0; i < answerKey.length(); i++)
			{
				if (answerKey[i] == studentAnswers[i])
				{
					studentGrade++;
				}
			}
			std::cout << studentGrade << std::endl;
			sumOfGrades += studentGrade;
		}
		averageScore = static_cast<double>(sumOfGrades) / static_cast<double>(totalStudents);
		std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
		std::cout << std::setfill(' ');
		std::cout << std::setprecision(2) << std::fixed;
		std::cout << std::setw(20) << std::left << "Average Score" << averageScore << std::endl;
	}
	else
	{
		std::cerr << "File cannot opened." << std::endl;
		return 1;
	}
	
	inFile.close();

	return 0;
}