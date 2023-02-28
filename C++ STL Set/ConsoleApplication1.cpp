#include <iostream>
#include <set> 
#include <string>
// C++ have 4 type of sets 1-Set, 2-Unordered Set, 3-Multiset, 4-Unordered Multiset.
// Sets don't allow the direct access to elements, so we can't use subscript operator and .at method.
// Sets don't have front and back, so there is no push_back, pop_back and front versions of this methods.

class Person
{
private:
    friend std::ostream& operator<<(std::ostream& os, const Person& obj)
    {
        os << obj.name << ":" << obj.age;
        return os;
    }
    std::string name;
    int age;

public:
    Person(std::string name = "None", int age = 0)
    {
        this->name = name;
        this->age = age;
    }
    bool operator<(const Person& rhs) const
    {
        if (rhs.age > age)
        {
            return true;
        }
        return false;
    }
    bool operator==(const Person& rhs) const 
    {
        if ((age == rhs.age) && (name == rhs.name))
        {
            return true;
        }
        return false;
    }
};

template<typename T>
void displaySet(const std::set<T>& s)
{
    std::cout << "[ ";
    for (const auto it : s)
    {
        std::cout << it << " ";
    }
    std::cout << "]" << std::endl;
}
int main()
{
    std::cout << "-----Basic Operations with Sets-----" << std::endl;
    std::set<int> s{ 1, 4, 3, 2, 5 };
    displaySet(s);

    s = { 1, 2, 3, 1, 1, 2, 2, 3, 3, 4 ,5 };
    displaySet(s);

    std::cout << "-----Insert Function with Sets-----" << std::endl;
    s.insert(0);
    s.insert(10);
    displaySet(s);

    std::cout << "-----Count Function with Sets-----" << std::endl;
    if (s.count(10)) // it will return 1(true) or 0(false)
    {
        std::cout << "10 is in the set." << std::endl;
    }
    else
    {
        std::cout << "10 is not in the set." << std::endl;
    }

    std::cout << "-----Find Funciton with Sets-----" << std::endl;
    auto it = s.find(5);
    std::cout << "Found : " << *it << std::endl;

    std::cout << "-----Clear Function with Sets-----" << std::endl;
    s.clear();
    displaySet(s);

    std::cout << "-----Classes with Sets-----" << std::endl;
    std::cout << "-----Emplace and Erase Functions with Sets-----" << std::endl;
    std::set<Person> stooges{
        {"Larry", 15},
        {"Moe", 26},
        {"Curly", 32}
    };
    displaySet(stooges);

    stooges.emplace("James", 50);
    stooges.emplace("Frank", 50); // Can't emplace because 50 already exists
    displaySet(stooges);

    auto prs = stooges.find(Person{ "Moe", 26 });
    if (prs != stooges.end())
    {
        stooges.erase(prs);
    }
    displaySet(stooges);

    prs = stooges.find(Person{ "XXX", 50 }); // It will remove James from the set uses < operator
    if (prs != stooges.end())
    {
        stooges.erase(prs);
    }
    displaySet(stooges);
     
    std::cout << "-----Boolalpha Function with std::string Sets-----" << std::endl;
    std::set<std::string> str{ "A", "B", "C" };
    displaySet(str);

    auto result = str.insert("D"); // insert method returns a std::pair
    displaySet(str);

    std::cout << std::boolalpha;
    std::cout << "First : " << *(result.first) << std::endl;
    std::cout << "Second : " << result.second << std::endl;
    std::cout << std::endl;

    result = str.insert("A");
    displaySet(str);

    std::cout << std::boolalpha;
    std::cout << "First : " << *(result.first) << std::endl;
    std::cout << "Second : " << result.second << std::endl;

    return 0;
}
