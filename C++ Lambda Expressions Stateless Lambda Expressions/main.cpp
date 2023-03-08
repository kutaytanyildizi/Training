#include <iostream>
#include <functional> // for std::function
#include <string>
#include <vector>
#include <algorithm>

class Person
{
private:
	friend std::ostream &operator<<(std::ostream& os, const Person& prs)
	{
		os << "[Person: " << prs.name << ":" << prs.age << "]";
		return os;
	}
	std::string name;
	int age;

public:
	Person(std::string name = "Unknown", int age = 0)
	{
		this->name = name;
		this->age = age;
	}
	Person(const Person& prs)
	{
		this->name = prs.name;
		this->age = prs.age;
	}
	~Person() = default;
	std::string getName() const
	{
		return name;
	}
	void setName(std::string name)
	{
		this->name = name;
	}
	int getAge() const
	{
		return age;
	}
	void setAge(int age)
	{
		this->age = age;
	}
};

void basicStatelessLambdaExpressions();
void basicStatelessLambdaExpressionsWithVariables();
void basicStatelessLambdaExpressionsWithClasses();
void filterVector(const std::vector<int>& vec, std::function <bool(int)> func);
void basicStatelessLambdaExpressionssWithFilterFunctions();
void basicStatelessLambdaExpressionsWithReturnTypeAuto();
void basicStatelessLambdaExpressionsWithAutoType();
void basicStatelessLambdaExpressionsWithSortAndForEach();

int main()
{
	basicStatelessLambdaExpressions();
	basicStatelessLambdaExpressionsWithVariables();
	basicStatelessLambdaExpressionsWithClasses();
	basicStatelessLambdaExpressionssWithFilterFunctions();
	basicStatelessLambdaExpressionsWithReturnTypeAuto();
	basicStatelessLambdaExpressionsWithAutoType();
	basicStatelessLambdaExpressionsWithSortAndForEach();
	return 0;
}

void basicStatelessLambdaExpressions()
{
	std::cout << "*****Basic Stateless Lambda Expressions*****" << std::endl;

	[]() {std::cout << "Hi" << std::endl; }();
	[](int x) {std::cout << x << std::endl; }(100);
	[](int x, int y) {std::cout << x + y << std::endl; }(100, 200);

	std::cout << "******************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatelessLambdaExpressionsWithVariables()
{
	std::cout << "*****Basic Stateless Lambda Expressions with Variables*****" << std::endl;

	auto l1 = []() {std::cout << "Hi" << std::endl; };
	l1();

	auto l2 = [](int x, int y) {std::cout << x + y << std::endl; };
	int num1{ 100 };
	int num2{ 200 };
	l2(10, 20);
	l2(num1, num2);

	auto l3 = [](int& x, int y) 
	{
		std::cout << "x: " << x << " y: " << y << std::endl; 
		x = 1000;
		y = 2000;
	};

	l3(num1, num2);
	std::cout << "Num 1: " << num1 << " Num 2: " << num2 << std::endl;

	std::cout << "*********************************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatelessLambdaExpressionsWithClasses()
{
	std::cout << "*****Basic Stateless Lambda Expressions with Classes*****" << std::endl;
	Person stooge("Larry", 18);
	
	std::cout << stooge << std::endl;

	auto l1 = [](Person p) {std::cout << p << std::endl; };
	l1(stooge);

	auto l2 = [](const Person& p) {std::cout << p << std::endl; };
	l2(stooge);

	auto l3 = [](Person& p)
	{
		p.setName("Frank");
		p.setAge(25);
		std::cout << p << std::endl;
	};
	l3(stooge);

	std::cout << stooge << std::endl;
	
	std::cout << "*******************************************************" << std::endl;
	std::cout << std::endl;
}

void filterVector(const std::vector<int>& vec, std::function <bool(int)> func) // this function returns a boolean and excepts a int
{
	std::cout << "[ ";
	for (int i : vec)
	{
		if (func(i))
		{
			std::cout << i << " ";
		}
	}
	std::cout << "]" << std::endl;
}

void basicStatelessLambdaExpressionssWithFilterFunctions()
{
	std::cout << "*****Basic Stateless Lambda Expressions with Filter Functions*****" << std::endl;
	std::vector<int> nums{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	filterVector(nums, [](int x) {return x > 50; });
	filterVector(nums, [](int x) {return x <= 30; });
	filterVector(nums, [](int x) { return x >= 30 && x <= 60; });
	std::cout << "******************************************************************" << std::endl;
	std::cout << std::endl;
}

auto makeLambda()
{
	return []() {std::cout << "This Lambda was made using the makeLambda Function." << std::endl; };
}

void basicStatelessLambdaExpressionsWithReturnTypeAuto()
{
	std::cout << "*****Basic Stateless Lambda Expressions with Auto Type Functions*****" << std::endl;
	auto l1 = makeLambda();
	l1();
	std::cout << "*********************************************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatelessLambdaExpressionsWithAutoType()
{
	std::cout << "*****Basic Stateless Lambda Expressions with Auto Type*****" << std::endl;
	auto l1 = [](auto x, auto y)
	{
		std::cout << "x: " << x << " y: " << y << std::endl;
	};

	l1(10, 20);
	l1(100.3, 200);
	l1(12.5, "Kutay");
	l1(Person("Larry", 18), Person("Curly", 22));
	std::cout << "***********************************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatelessLambdaExpressionsWithSortAndForEach()
{
	std::cout << "*****Basic Lambda Expressions With Sort and For Each*****" << std::endl;
	std::vector<Person> stooges
	{
		{"Larry", 18},
		{"Moe", 30},
		{"Curly", 25}
	};
	std::sort(begin(stooges), end(stooges), [](const Person& p1, const Person& p2) 
	{
		return p1.getName() < p2.getName();
	});

	std::for_each(begin(stooges), end(stooges), [](const Person& p) 
	{
		std::cout << p << std::endl;
	});

	std::cout << std::endl;

	std::sort(begin(stooges), end(stooges), [](const Person& p1, const Person& p2) 
	{
		return p1.getAge() < p2.getAge();
	});

	std::for_each(begin(stooges), end(stooges), [](const Person& p) 
	{
		std::cout << p << std::endl;
	});

	std::cout << "*********************************************************" << std::endl;
	std::cout << std::endl;
}