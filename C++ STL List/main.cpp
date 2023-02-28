#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>

class Person
{
private:
    friend std::ostream& operator<<(std::ostream& os, const Person& p)
    {
        os << p.name << " : " << p.age;
        return os;
    }
    std::string name;
    int age;

public:
    Person(std::string name, int age = 0)
    {
        this->name = name;
        this->age = age;
    }
    bool operator<(const Person& rhs)
    {
        if (rhs.age > age)
        {
            return true;
        }
        return false;
    }
    bool operator==(const Person& rhs)
    {
        if ((rhs.age == age) && (rhs.name == name))
        {
            return true;
        }
        return false;
    }
};

template <typename T>
void displayList(const std::list<T>& l)
{
    std::cout << "[";
    for (const auto it : l)
    {
        std::cout << it << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::list<int> l = { 1, 2, 3, 4, 5 };

    std::cout << "-----List Size-Front-Back Functions----" << std::endl;
    std::cout << l.size() << std::endl;
    std::cout << l.max_size() << std::endl;
    std::cout << l.front() << std::endl;
    std::cout << l.back() << std::endl;

    std::cout << "-----List Insert and Erase Functions-----" << std::endl;
    auto it = std::find(l.begin(), l.end(), 3);

    l.insert(it, 10);
    displayList(l);

    l.erase(it);
    displayList(l);

    std::cout << "-----List Resize Function-----" << std::endl;
    l.resize(2);
    displayList(l);

    l.resize(5);
    displayList(l);

    std::cout << "-----List Push-Back and Push-Front Functions-----" << std::endl;
    l.push_back(12);
    l.push_back(22);
    l.push_front(48);
    displayList(l);

    std::cout << "-----List with Classes-----" << std::endl;
    std::list<Person> stooges{ {"Kutay", 22}, {"Egemen", 23}, {"B�lent", 50} };
    displayList(stooges);
    std::string name;
    int age;

    std::cout << "Enter the name of the next stooges : ";
    std::cin >> name;
    std::cout << "Enter the age of the next stooges : ";
    std::cin >> age;
    stooges.emplace_back(name, age);
    displayList(stooges);

    auto prs = std::find(stooges.begin(), stooges.end(), Person{ "B�lent", 50 });
    if (prs != stooges.end())
    {
        stooges.emplace(prs, "Ekrem", 29);
    }
    displayList(stooges);

    stooges.sort();
    displayList(stooges);

    return 0;
}

