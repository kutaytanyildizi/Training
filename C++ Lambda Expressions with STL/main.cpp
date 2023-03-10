#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Person
{
	friend std::ostream& operator<<(std::ostream& os, const Person& prs)
	{
		os << "[Person:" << prs.name << ":" << prs.age << "]";
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
};

class PasswordValidator1
{
private:
	char restrictedSymbol{ '$'};

public:
	bool isValid(std::string password)
	{
		return std::all_of(password.begin(), password.end(), [this](char character) {return character != restrictedSymbol; });
	}
};

class PasswordValidator2
{
private:
	std::vector<char> restrictedSymbols{ '!', '$', '+' };

public:
	bool isValid(std::string password)
	{
		return std::all_of(password.begin(), password.end(), [this](char character)
			{
				return std::none_of(restrictedSymbols.begin(), restrictedSymbols.end(), [character](char symbol)
				{
					return character == symbol;});});
	}
};

void basicLambdaExpressionsWithVectors(); 
void basicLambdaExperssionsWithIsPermutationMethod(); 
void basicLambdaExpressionsWithTransformAlgorithm(); 
void basicLambdaExpressionsWithRemoveIfAlgorithm();
void basicLambdaExpressionsWithSortAlgorithm();
bool inBetween(const std::vector<int>& nums, int startValue, int endValue);
void basicLambdaExpressionsWithInBetweenFunction();
void basicLambdaExpressionsWithPasswordValidatorClasses();

int main() 
{ 
	basicLambdaExpressionsWithVectors();
	basicLambdaExperssionsWithIsPermutationMethod();
	basicLambdaExpressionsWithTransformAlgorithm();
	basicLambdaExpressionsWithRemoveIfAlgorithm();
	basicLambdaExpressionsWithSortAlgorithm();
	basicLambdaExpressionsWithInBetweenFunction();
	basicLambdaExpressionsWithPasswordValidatorClasses();

	return 0; 
}

void basicLambdaExpressionsWithVectors()
{
	std::cout << "*****Basic Lambda Expressions with Vectors*****" << std::endl;

	std::vector<int> vec{ 10, 20, 30, 40, 50 };
	
	std::for_each(vec.begin(), vec.end(), [](int num) {std::cout << num << " "; });
	std::cout << std::endl;

	std::cout << "***********************************************" << std::endl;
	std::cout << std::endl;
}

void basicLambdaExperssionsWithIsPermutationMethod()
{
	/*is_permutation Non modifying sequence operator
	Tests whetever two triangles are equivalent 
	Triangles are defined by a vector of three points in any order*/

	std::cout << "*****Basic Lambda Expressions with Is Permutation Method*****" << std::endl;

	struct Point
	{
		int x;
		int y;
	};

	Point pt1{ 1, 2 };
	Point pt2{ 4, 3 };
	Point pt3{ 3, 5 };
	Point pt4{ 3, 1 };

	std::vector<Point> Triangle1{ pt1, pt2, pt3 };
	std::vector<Point> Triangle2{ pt2, pt3, pt1 };
	std::vector<Point> Triangle3{ pt4, pt2, pt1 };

	if (std::is_permutation(Triangle1.begin(), Triangle1.end(), Triangle2.begin(), [](Point lhs, Point rhs) {return lhs.x == rhs.x && lhs.y == rhs.y; }))
	{
		std::cout << "Triangle 1 is equivalent to Triangle 2." << std::endl;
	}
	else
	{
		std::cout << "Triangle 1 is not equivalent to Triangle 2." << std::endl;
	}

	if (std::is_permutation(Triangle2.begin(), Triangle2.end(), Triangle3.begin(), [](Point lhs, Point rhs) {return lhs.x == rhs.x && lhs.y == rhs.y; }))
	{
		std::cout << "Triangle 2 is equivalent to Triangle 3." << std::endl;
	}
	else
	{
		std::cout << "Triangle 2 is not equivalent to Triangle 3." << std::endl;
	}

	std::cout << "*************************************************************" << std::endl;
	std::cout << std::endl;
}

void basicLambdaExpressionsWithTransformAlgorithm()
{
	/*transform - Modifying sequence operator
	In this case each score incremented by 5 points*/

	std::cout << "*****Basic Lambda Expressions with Transform Algortihm*****" << std::endl;

	std::vector<int> scores{ 93, 88, 76, 63, 56 };
	int bonusPoints{ 5 };
	
	std::transform(scores.begin(), scores.end(), scores.begin(), [bonusPoints](int score) {return score += bonusPoints; });

	for (int score : scores)
	{
		std::cout << score << " ";
	}
	std::cout << std::endl;

	std::cout << "***********************************************************" << std::endl;
	std::cout << std::endl;
}

void basicLambdaExpressionsWithRemoveIfAlgorithm()
{
	std::cout << "*****Basic Lambda Expressions with Remove If Algorithm*****" << std::endl;

	std::vector<int> nums{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	nums.erase(std::remove_if(nums.begin(), nums.end(), [](int num) {return num % 2 == 0; }));

	for (int num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << "***********************************************************" << std::endl;
	std::cout << std::endl;
}

void basicLambdaExpressionsWithSortAlgorithm()
{
	std::cout << "*****Basic Lambda Expressions with Sort Algorithm*****" << std::endl;

	Person person1("Larry", 18);
	Person person2("Moe", 30);
	Person person3("Curly", 25);

	std::vector<Person> people{ person1, person2, person3 };

	std::sort(people.begin(), people.end(), [](Person lhs, Person rhs) {return lhs.getName() < rhs.getName(); });

	for (Person person : people)
	{
		std::cout << person << std::endl;
	}

	std::cout << std::endl;

	std::sort(people.begin(), people.end(), [](Person lhs, Person rhs) {return lhs.getAge() > rhs.getAge(); });

	for (Person person : people)
	{
		std::cout << person << std::endl;
	}

	std::cout << "******************************************************" << std::endl;
	std::cout << std::endl;
}

bool inBetween(const std::vector<int> &nums, int startValue, int endValue)
{
	// Tests whetever all elements contained within the sequence satisfy the condition defined by the passed predicate Lambda.

	bool result{ false };
	result = std::all_of(nums.begin(), nums.end(), [startValue, endValue](int value) {return value >= startValue && value <= endValue; });
	return result;
}

void basicLambdaExpressionsWithInBetweenFunction()
{
	std::cout << "*****Basic Lambda Expressions with In Between Function*****" << std::endl;

	std::cout << std::boolalpha;

	std::vector<int> nums(10);
	std::iota(nums.begin(), nums.end(), 1); // From numeric library iota is set numbers 1 to 10 in nums vector.

	for (int num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << inBetween(nums, 50, 60) << std::endl;
	std::cout << inBetween(nums, 1, 10) << std::endl;
	std::cout << inBetween(nums, 5, 7) << std::endl;

	std::cout << "***********************************************************" << std::endl;
	std::cout << std::endl;
}

void basicLambdaExpressionsWithPasswordValidatorClasses()
{
	std::cout << "*****Basic Lambda Expressions with Password Validator Classes*****" << std::endl;

	// Password Validator 1
	
	std::string password{ "holywood1$" };
	PasswordValidator1 pv1;

	if (pv1.isValid(password))
	{
		std::cout << "The password " << password << " is valid!" << std::endl;
	}
	else
	{
		std::cout << "The password " << password << " is not valid!" << std::endl;
	}

	password = "holywood1";
	if (pv1.isValid(password))
	{
		std::cout << "The password " << password << " is valid!" << std::endl;
	}
	else
	{
		std::cout << "The password " << password << " is not valid!" << std::endl;
	}
	std::cout << std::endl;

	// Password Validator 2
	
	password = "C++Rocks!";
	PasswordValidator2 pv2;

	if (pv2.isValid(password))
	{
		std::cout << "The password " << password << " is valid!" << std::endl;
	}
	else
	{
		std::cout << "The password " << password << " is not valid!" << std::endl;
	}

	password = "CPlusPlusRocks!";
	if (pv2.isValid(password))
	{
		std::cout << "The password " << password << " is valid!" << std::endl;
	}
	else
	{
		std::cout << "The password " << password << " is not valid!" << std::endl;
	}

	password = "CPlusPlusRocks";
	if (pv2.isValid(password))
	{
		std::cout << "The password " << password << " is valid!" << std::endl;
	}
	else
	{
		std::cout << "The password " << password << " is not valid!" << std::endl;
	}

	std::cout << "******************************************************************" << std::endl;
	std::cout << std::endl;
}