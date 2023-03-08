#include <iostream>
#include <vector>
#include <algorithm>

class Person
{
private:
	friend std::ostream& operator<<(std::ostream& os, const Person& prs)
	{
		os << "[" << prs.name << ":" << prs.age << "]";
		return os;
	}
	std::string name;
	int age;

public:
	Person(std::string name = "Unkonown", int age = 0)
	{
		this->name = name;
		this->age = age;
	}
	~Person() = default;
	Person(const Person& prs)
	{
		this->name = prs.name;
		this->age = prs.age;
	}
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
	
	// This three definitions do the same thing.
	auto changePerson1() { return [this] (std::string newName, int newAge) {name = newName; age = newAge; }; } // Recommended usage // [*this] this definition captures by value.
	auto changePerson2() { return [=](std::string newName, int newAge) {name = newName; age = newAge; }; } // Contrary to popular belief, this definition makes the captures as a reference. This definition is valid for C++20
	auto changePerson3() { return [&](std::string newName, int newAge) {name = newName; age = newAge; }; }
};

class Lambda
{
private:
	int y;

public:
	Lambda(int y)
	{
		this->y = y;
	};
	void operator() (int x) const
	{
		std::cout << x + y << std::endl;
	};
};

class People
{
private:
	std::vector<Person> people;
	int maxPeople;

public:
	People(int max = 10)
	{
		maxPeople = max;
	}
	People(const People& p) = default;
	void add(std::string name, int age)
	{
		people.emplace_back(name, age);
	}
	void setMaxPeople(int max)
	{
		maxPeople = max;
	}
	int getMaxPeople() const
	{
		return maxPeople;
	}

	/*This method returns a vector of Person objects in
	people who's age > maxAge and it limits the number of 
	persons returned to be <= the member variable maxPeople.*/
	//That the Lambda in this example captures this, by reference and by value.
	std::vector<Person> getPeople(int maxAge)
	{
		std::vector<Person> result;
		int count{};
		std::copy_if(people.begin(), people.end(), std::back_inserter(result), [this, &count, maxAge](const Person& prs) {return prs.getAge() > maxAge && ++count <= maxPeople; });
		return result;
	}
};

int global = 1000;

void basicStatefulLambdaExpressions();
void basicStatefulLambdaExpressionsWithMutable();
void basicStatefulLambdaExpressionsWithMutableAndReference();
void basicStatefulLambdaExpressionsWithMutableAndEqualityOperator();
void basicStatefulLambdaExpressionsWithReference();
void basicStatefulLambdaExpressionsWithSpecificReference();
void basicStatefulLambdaExpressionsWithSpecificValue();
void basicStatefulLambdaExpressionsWithClasses();
void basicStatefulLambdaExpressionsWithUserDefinedLambdaClass();
void basicStatefulLambdaExpressionsWithPeopleClass();

int main()
{
	basicStatefulLambdaExpressions();
	basicStatefulLambdaExpressionsWithMutable();
	basicStatefulLambdaExpressionsWithMutableAndReference();
	basicStatefulLambdaExpressionsWithMutableAndEqualityOperator();
	basicStatefulLambdaExpressionsWithReference();
	basicStatefulLambdaExpressionsWithSpecificReference();
	basicStatefulLambdaExpressionsWithSpecificValue();
	basicStatefulLambdaExpressionsWithClasses();
	basicStatefulLambdaExpressionsWithUserDefinedLambdaClass();
	basicStatefulLambdaExpressionsWithPeopleClass();
	return 0;
}

void basicStatefulLambdaExpressions()
{
	std::cout << "*****Basic Statefull Lambda Expressions*****" << std::endl;

	int local = 100;

	auto l = [local]() 
	{
		// local += 100 this definition causes error because there is no mutable keyword.
		std::cout << local << std::endl;
		std::cout << global << std::endl;
	};
	l();
	std::cout << local << std::endl;
	l();
	
	std::cout << "********************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatefulLambdaExpressionsWithMutable()
{
	std::cout << "*****Basic Stateful Lambda Expressions with Mutable Keyword*****" << std::endl;

	int local = 100;

	auto l = [local]() mutable
	{
		local += 100;
		std::cout << local << std::endl;
	};

	/*When we call a lambda expression it creates a class. This class has constructor and call operator operator(). Captured local value becomes a variable of this class.*/
	l();
	std::cout << local << std::endl;
	l();
	std::cout << local << std::endl;

	std::cout << "****************************************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatefulLambdaExpressionsWithMutableAndReference()
{
	std::cout << "*****Basic Stateful Lambda Expressions with Mutable and Reference*****" << std::endl;

	int local = 100;

	auto l = [&local]() mutable
	{
		local += 100;
		std::cout << local << std::endl;
	};

	l();
	std::cout << local << std::endl;

	std::cout << "**********************************************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatefulLambdaExpressionsWithMutableAndEqualityOperator()
{
	std::cout << "*****Basic Stateful Lambda Expressions with Mutable and Equality Operator*****" << std::endl;

	int local1 = 100;
	int local2 = 200;
	int local3 = 300; // Local 3 is not captured in the lambda since it is not used. Only variables used within the lambda body are captured by value.

	auto l = [=]() mutable // Operator (=) capturing everything by value.
	{
		local1 += 100;
		local2 += 100;
		std::cout << local1 << std::endl;
		std::cout << local2 << std::endl;
	};

	l();
	std::cout << local1 << std::endl;
	std::cout << local2 << std::endl;
	std::cout << local3 << std::endl;

	std::cout << "******************************************************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatefulLambdaExpressionsWithReference()
{
	std::cout << "*****Basic Stateful Lambda Expressions with Reference*****" << std::endl;

	int local1{ 100 };
	int local2{ 200 };
	int local3{ 300 };

	auto l = [&]() // & captures everything by reference.
	{
		local1 += 100;
		local2 += 100;
		local3 += 100;
		std::cout << local1 << std::endl;
		std::cout << local2 << std::endl;
		std::cout << local3 << std::endl;
	};

	l();

	std::cout << local1 << std::endl;
	std::cout << local2 << std::endl;
	std::cout << local3 << std::endl;

	std::cout << "**********************************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatefulLambdaExpressionsWithSpecificReference()
{
	std::cout << "*****Basic Stateful Lambda Expressions with Specific Reference*****" << std::endl;

	int local1{ 100 };
	int local2{ 200 };
	int local3{ 300 };

	auto l = [=, &local2]()mutable // Default capture by value but for Local 2 capture by reference.
	{
		local1 += 100;
		local2 += 100;
		local3 += 100;
		std::cout << local1 << std::endl;
		std::cout << local2 << std::endl;
		std::cout << local3 << std::endl;
	};

	l();

	std::cout << local1 << std::endl;
	std::cout << local2 << std::endl;
	std::cout << local3 << std::endl;

	std::cout << "*******************************************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatefulLambdaExpressionsWithSpecificValue()
{
	std::cout << "*****Basic Stateful Lambda Expressions with Specific Value*****" << std::endl;
	
	int local1{ 100 };
	int local2{ 200 };
	int local3{ 300 };

	auto l = [&, local1, local3]() mutable // Default capture by reference but Local 1 and Local 3 capture by value.
	{
		local1 += 100;
		local2 += 100;
		local3 += 100;
		std::cout << local1 << std::endl;
		std::cout << local2 << std::endl;
		std::cout << local3 << std::endl;
	};

	l();

	std::cout << local1 << std::endl;
	std::cout << local2 << std::endl;
	std::cout << local3 << std::endl;

	std::cout << "***************************************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatefulLambdaExpressionsWithClasses()
{
	std::cout << "*****Basic Stateful Lambda Expressions with Classes*****" << std::endl;

	Person person("Larry", 18);
	std::cout << person << std::endl;

	auto changePerson1 = person.changePerson1();
	changePerson1("Moe", 30);
	std::cout << person << std::endl;

	auto changePerson2 = person.changePerson2();
	changePerson2("Curly", 25);
	std::cout << person << std::endl;

	auto changePerson3 = person.changePerson3();
	changePerson3("Frank", 34);
	std::cout << person << std::endl;

	std::cout << "********************************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatefulLambdaExpressionsWithUserDefinedLambdaClass()
{
	std::cout << "*****Basic Statedul Lambda Expressions with User Defined Lambda Class*****" << std::endl;

	int y{ 100 };

	Lambda lambda1(y);
	auto lambda2 = [y](int x) {std::cout << x + y << std::endl; };

	lambda1(200);
	lambda2(200);

	std::cout << "**************************************************************************" << std::endl;
	std::cout << std::endl;
}

void basicStatefulLambdaExpressionsWithPeopleClass()
{
	std::cout << "*****Basic Stateful Lambda Expressions with People Class*****" << std::endl;
	
	People friends;
	friends.add("Larry", 18);
	friends.add("Curly", 25);
	friends.add("Moe", 35);
	friends.add("Frank", 28);
	friends.add("James", 65);

	auto result = friends.getPeople(17);

	std::cout << std::endl;
	for (const auto& p : result)
	{
		std::cout << p << std::endl;
	}

	friends.setMaxPeople(3);
	
	result = friends.getPeople(17);

	std::cout << std::endl;
	for (const auto& p : result)
	{
		std::cout << p << std::endl;
	}

	result = friends.getPeople(50);

	std::cout << std::endl;
	for (const auto& p : result)
	{
		std::cout << p << std::endl;
	}

	std::cout << "*************************************************************" << std::endl;
	std::cout << std::endl;
}