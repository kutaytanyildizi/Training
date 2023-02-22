#include <iostream>
#include <vector>
#include <string>

template<typename t>
t min(t parameter1, t parameter2)
{
	if (parameter1 < parameter2) 
	{
		return parameter1;
	}
	return parameter2;
}

template<typename T1, typename T2>
void func(T1 a, T2 b)
{
	std::cout << a << " || " << b << std::endl;
}

struct Person
{
	std::string name;
	int age;
	bool operator<(const Person& rhs) const
	{
		if (this->age < rhs.age)
		{
			return true;
		}
		return false;
	}

	friend std::ostream& operator<<(std::ostream& os, const Person& obj)
	{
		os << obj.name << ": " << obj.age;
		return os;
	}
};

int main()
{
	Person curly{ "Curly", 50 };
	Person moe{ "Moe", 30 };
	Person younger = min(curly, moe);

	std::cout << curly << std::endl;
	std::cout << younger << std::endl;

	std::cout << min(2, 3) << std::endl;
	std::cout << min('A', 'B') << std::endl;
	std::cout << min(12.5, 9.5) << std::endl;
	std::cout << min(5+2*2, 7+40) << std::endl;

	func(moe, 20);
	func("Kutay", "Deniz");
	func(1000, std::string("Frank"));
 	
	return 0;
}

