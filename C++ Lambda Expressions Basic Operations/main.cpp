#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Multiplier
{
private:
	int num{};

public:
	Multiplier(int n = 0)
	{
		num = n;
	}
	int operator()(int n) const
	{
		return num * n;
	}
};

template<typename T>
struct Displayer
{
	void operator()(const T& data)
	{
		std::cout << data << " ";
	}
};

struct SquareFunctor
{
	void operator() (int x) 
	{
		std::cout << x * x << " ";
	}
};

int main()
{
	SquareFunctor square;
	square(4);

	Displayer<int> d1;
	Displayer<std::string> d2;
	d1(100);
	d2("Frank");
	std::cout << std::endl;

	std::cout << "*****Using For Each Method with Structs*****" << std::endl;
	std::vector<int> vec1{ 1, 2, 3, 4, 5 };
	std::vector<std::string> vec2{ "Larry", "Moe", "Curly" };

	std::for_each(vec1.begin(), vec1.end(), square);
	std::cout << std::endl;

	std::for_each(vec1.begin(), vec1.end(), Displayer<int>());
	std::cout << std::endl;

	std::for_each(vec1.begin(), vec1.end(), d1);
	std::cout << std::endl;

	std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>());
	std::cout << std::endl;

	std::for_each(vec2.begin(), vec2.end(), d2);
	std::cout << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << std::endl;

	std::cout << "*****Using For Each Method with Lambda Expressions*****" << std::endl;

	std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * x << " "; });
	std::cout << std::endl;

	std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * 10 << " "; });
	std::cout << std::endl;

	std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x << " "; });
	std::cout << std::endl;

	std::for_each(vec2.begin(), vec2.end(), [](std::string str) {std::cout << str << " "; });
	std::cout << std::endl;
	std::cout << "*******************************************************" << std::endl;
	std::cout << std::endl;
 
	std::cout << "*****Using For Each and Transform Methods with Classes and Lambda Expressions*****" << std::endl;
	Multiplier mult(100);
	
	std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);
	std::for_each(vec1.begin(), vec1.end(), d1);
	std::cout << std::endl;
	
	vec1 = { 1, 2, 3, 4, 5 };
	std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) {return x * 100; });
	std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x << " "; });
	std::cout << std::endl;
	std::cout << "**********************************************************************************" << std::endl;
	std::cout << std::endl;
	return 0;
}