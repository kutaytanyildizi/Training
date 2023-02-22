#include <iostream>
#include <string>
#include <vector>

template<typename T>
class Item
{
private:
	std::string name;
	T value;

public:
	Item(std::string name, T value)
	{
		this->name = name;
		this->value = value;
	}

	std::string getName() const
	{
		return name;
	}

	T getValue() const
	{
		return value;
	}
};

template<typename T1, typename T2>
struct MyPair
{
	T1 first;
	T2 second;
};

int main()
{
	Item<int> Table("Table", 1500);
	Item<double> Computer("Computer", 15000.450);
	Item<std::string> Door("Door", "600");
	std::vector<Item<int>> vec;

	std::cout << Table.getName() << " " << Table.getValue() << std::endl;

	vec.push_back(Item<int>("Monitor", 2000));
	vec.push_back(Item<int>("Mouse", 500));
	vec.push_back(Item<int>("Mobile Phone", 200000));

	for (auto it : vec)
	{
		std::cout << it.getName() << " : " << it.getValue() << std::endl;
	}

	MyPair<std::string, int> Kutay{ "Kutay", 22 };
	MyPair<int, double> Boss{ 20, 50.5 };
	std::vector<MyPair<int, double>> myVec;

	std::cout << Kutay.first << " " << Kutay.second << std::endl;
	std::cout << Boss.first << " " << Boss.second << std::endl;

	return 0;
}

