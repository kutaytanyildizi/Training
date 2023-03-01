#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

std::string cleanString(const std::string& s);
void displayWords(const std::map<std::string, int>& words);
void displayWords(const std::map<std::string, std::set<int>>& words);
void mapNumberOfOccurs();
void mapSetNumberOfLines();


int main()
{
	mapNumberOfOccurs();
	std::cout << "|||||||||||||||||||||||||||||||" << std::endl;
	mapSetNumberOfLines();
	return 0;
}

std::string cleanString(const std::string& s)
{
	std::string resultString;
	for (char c : s)
	{
		if (!(c == '.' || c == ',' || c == ';' || c == ':'))
		{
			resultString += c;
		}
	}
	return resultString;
}

void displayWords(const std::map<std::string, int>& words)
{
	std::cout << std::setw(15) << std::left << "Word" << std::setw(5) << std::left << "Count" << std::endl;
	std::cout << "==========================" << std::endl;
	for (auto it : words)
	{
		std::cout << std::setw(15) << std::left << it.first << std::setw(5) << std::left << it.second << std::endl;
	}
}

void displayWords(const std::map<std::string, std::set<int>>& words)
{
	std::cout << std::setw(15) << std::left << "Word" << std::setw(20) << std::left << "Occurences" << std::endl;
	std::cout << "=========================" << std::endl;
	for (auto it : words)
	{
		std::cout << std::setw(15) << std::left << it.first << std::left << "[ ";
		for (auto elem : it.second)
		{
			std::cout << elem << " ";
		}
		std::cout << "]" << std::endl;
	}
}

void mapNumberOfOccurs()
{
	std::map<std::string, int> words;
	std::string line;
	int lineNumber{};
	std::string word;
	std::ifstream inFile{ "words.txt" };
	if (inFile)
	{
		while (std::getline(inFile, line))
		{
			lineNumber++;
			std::stringstream ss(line);
			while (ss >> word)
			{
				word = cleanString(word);
				words[word]++;
			}
		}
		inFile.close();
		displayWords(words);
	}
	else
	{
		std::cout << "Error when openning input file." << std::endl;
	}
}

void mapSetNumberOfLines()
{
	std::map<std::string, std::set<int>> words;
	std::string line;
	int lineNumber{};
	std::string word;
	std::ifstream inFile{ "words.txt" };
	if (inFile)
	{
		while (std::getline(inFile, line))
		{
			lineNumber++;
			std::stringstream ss(line);
			while (ss >> word)
			{
				word = cleanString(word);
				words[word].insert(lineNumber);
			}
		}
		inFile.close();
		displayWords(words);
	}
	else
	{
		std::cout << "Error when opening input file." << std::endl;
	}
}