#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person
{
private:
    std::string name;
    int age;

public:
    Person(std::string name = " ", int age = 0)
    {
        this->name = name;
        this->age = age;
    }
    bool operator<(const Person& rhs)
    {
        if (this->age < rhs.age)
        {
            return true;
        }
        return false;
    }
    bool operator==(const Person& rhs)
    {
        if ((this->name == rhs.name) && (this->age == rhs.age))
        {
            return true;
        }
        return false;
    }
};

int main()
{ 
    std::cout << "-----Find Function-----" << std::endl;

    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    auto loc = std::find(vec.begin(), vec.end(), 4);

    if (loc != vec.end())
    {
        std::cout << "Number is found: " << *loc << std::endl;
    }
    else
    {
        std::cout << "Couldn't find the number." << std::endl;
    }

    auto it = std::find(vec.begin(), vec.end(), 120);

    if (it != vec.end())
    {
        std::cout << "Number is found: " << *it << std::endl;
    }
    else
    {
        std::cout << "Couldn't find the number." << std::endl;
    }

    std::list<Person> players = { {"Kutay", 22}, {"Egemen", 25}, {"Deniz", 23}, {"Doğus", 42} };

    auto loc1 = std::find(players.begin(), players.end(), Person{ "Kutay", 22 });
    auto loc2 = std::find(players.begin(), players.end(), Person{ "Kutay", 32 });

    if (loc1 != players.end())
    {
        std::cout << "Kutay found." << std::endl;
    }
    else
    {
        std::cout << "Kutay not found." << std::endl;
    }

    if (loc2 != players.end())
    {
        std::cout << "Kutay found." << std::endl;
    }
    else
    {
        std::cout << "Kutay not found." << std::endl;
    }

    std::cout << "========================" << std::endl;
    std::cout << "-----Count Function-----" << std::endl;

    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);

    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurences found." << std::endl;

    std::cout << "==========================" << std::endl;
    std::cout << "----Count If Function-----" << std::endl;

    vec.push_back(100);
    vec.push_back(50);

    //Lambda Expressions
    int div = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 == 0;});
    std::cout << div << " even numbers found in Vector." << std::endl;

    //Lambda Expressions
    div = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 != 0; });
    std::cout << div << " odd numbers found in Vector." << std::endl;

    std::cout << "==========================" << std::endl;
    std::cout << "-----Replace Funciton-----" << std::endl;

    for (auto it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 27);

    for (auto it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    std::cout << "=========================" << std::endl;
    std::cout << "-----All Of Function-----" << std::endl;

    if (std::all_of(vec.begin(), vec.end(), [](int x) {return x > 10; }))
    {
        std::cout << "All the elements of Vector are greater than 10." << std::endl;
    }
    else
    {
        std::cout << "All the elements of Vector are not greater than 10." << std::endl;
    }

    std::cout << "============================" << std::endl;
    std::cout << "-----Transform Function-----" << std::endl;

    std::string str = "This is a Transform Function Test.";
    std::cout << "Before the Transform Function -> [" << str << "]" << std::endl;
    std::transform(str.begin(), str.end(), str.begin(), toupper);
    std::cout << "After the Transform Function -> [" << str << "]" << std::endl;

 	return 0;
}
