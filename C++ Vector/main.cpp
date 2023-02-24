#include <iostream>
#include <vector>
#include <algorithm>  

class Person
{
private:
    friend std::ostream& operator<<(std::ostream& os, const Person& obj)
    {
        os << "(" << obj.name << " : " << obj.age << ")";
        return os;
    }
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
        if (rhs.age > this->age)
        {
            return true;
        }
        return false;
    }
    bool operator==(const Person& rhs)
    {
        if ((this->age == rhs.age) && (this->name == rhs.name))
        {
            return true;
        }
        return false;
    }
};

template<typename T>
void displayVec(const std::vector<T>& vec)
{
    std::cout << "[";
    for (const auto it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << "]" << std::endl;
}

void vecSizeAndCapacity();
void vecAssignment();
void vecWithClass();
void vecFrontAndBack();
void vecClearAndErase();
void vecSwap();
void vecSort();
void vecCopyAndBackInserter();
void vecTransform();
void vecFindAndInsert();

int main()
{ 
    vecSizeAndCapacity();
    vecAssignment();
    vecWithClass();
    vecFrontAndBack();
    vecClearAndErase();
    vecSwap();
    vecSort();
    vecCopyAndBackInserter();
    vecTransform();
    vecFindAndInsert();

 	return 0;
}

void vecSizeAndCapacity()
{
    std::cout << "==================================" << std::endl;
    std::cout << "-----Vector Size and Capacity-----" << std::endl;

    std::vector<int> vec{ 1, 2, 3, 4, 5 };
    displayVec(vec);
    std::cout << "Vector Size : " << vec.size() << std::endl;
    std::cout << "Vector Max Size : " << vec.max_size() << std::endl;
    std::cout << "Vector Capacity : " << vec.capacity() << std::endl;

    vec.push_back(6);
    std::cout << std::endl;
    displayVec(vec);
    std::cout << "Vector Size : " << vec.size() << std::endl;
    std::cout << "Vector Max Size : " << vec.max_size() << std::endl;
    std::cout << "Vector Capacity : " << vec.capacity() << std::endl;

    vec.shrink_to_fit(); //C++11
    std::cout << std::endl;
    displayVec(vec);
    std::cout << "Vector Size : " << vec.size() << std::endl;
    std::cout << "Vector Max Size : " << vec.max_size() << std::endl;
    std::cout << "Vector Capacity : " << vec.capacity() << std::endl;

    vec.reserve(100);
    std::cout << std::endl;
    std::cout << "Vector Size : " << vec.size() << std::endl;
    std::cout << "Vector Max Size : " << vec.max_size() << std::endl;
    std::cout << "Vector Capacity : " << vec.capacity() << std::endl;
}

void vecAssignment()
{
    std::cout << "\n===========================" << std::endl;
    std::cout << "-----Vector Assignment-----" << std::endl;

    std::vector<int> vec{ 1, 2, 3, 4, 5 };
    displayVec(vec);

    vec[0] = 100;
    vec.at(1) = 121;
    displayVec(vec);
}
 
void vecWithClass()
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "-----Vectors With Classes-----" << std::endl;

    std::vector<Person> stooges;
    Person p1("Kutay", 22);
    displayVec(stooges);

    stooges.push_back(p1);

    stooges.push_back({ "Deniz", 23 });
    displayVec(stooges);

    stooges.emplace_back("Egemen", 25);
    displayVec(stooges);
}

void vecFrontAndBack()
{
    std::cout << "\n=========================================" << std::endl;
    std::cout << "-----Vector Front and Back Functions-----" << std::endl;
    
    std::vector<Person> stooges{ {"Kutay", 22}, {"Deniz", 23}, {"Egemen", 25} };
    displayVec(stooges);

    std::cout << stooges.front() << std::endl;
    std::cout << stooges.back() << std::endl;

    stooges.pop_back();
    displayVec(stooges);
}

void vecClearAndErase()
{
    std::cout << "\n==========================================" << std::endl;
    std::cout << "-----Vector Clear and Erase Functions-----" << std::endl;

    std::vector<int> vec{ 1, 2, 3, 4, 5 };
    displayVec(vec);

    vec.clear();
    displayVec(vec);
    
    vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    displayVec(vec);
    
    vec.erase(vec.begin(), vec.begin() + 2);
    displayVec(vec);

    /*vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto it = vec.begin(); it < vec.end(); it++)
    {
        if (*it % 2 == 0)
        {
            vec.erase(it);
        }
    }
    displayVec(vec);*/
}

void vecSwap()
{
    std::cout << "\n=====================" << std::endl;
    std::cout << "-----Vector Swap-----" << std::endl;

    std::vector<int> vec1{ 1, 2, 3, 4, 5 };
    std::vector<int> vec2{ 10, 20, 30, 40, 50 };

    displayVec(vec1);
    displayVec(vec2);

    std::cout << std::endl;

    vec1.swap(vec2);
    displayVec(vec1);
    displayVec(vec2);
}

void vecSort()
{
    std::cout << "\n=====================" << std::endl;
    std::cout << "-----Vector Sort-----" << std::endl;

    std::vector<int> vec{ 1, 21, 3, 40, 12 };

    std::cout << "Before the Sort." << std::endl;
    displayVec(vec); 
    std::cout << "After the Sort." << std::endl;
    std::sort(vec.begin(), vec.end());
    displayVec(vec);
}

void vecCopyAndBackInserter()
{
    std::cout << "\=================================================" << std::endl;
    std::cout << "-----Vector Copy and Back Inserter Functions-----" << std::endl;

    std::vector<int> vec1{ 1, 2, 3, 4, 5 };
    std::vector<int> vec2{ 10, 20, 30, 40, 50 };

    displayVec(vec1);
    displayVec(vec2);
    std::cout << std::endl;

    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    displayVec(vec1);
    displayVec(vec2);
    std::cout << std::endl;

    vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vec2 = { 10, 20, 30, 40 ,50 ,60 ,70, 80, 90, 100 };

    displayVec(vec1);
    displayVec(vec2);
    std::cout << std::endl;

    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2), [](int x) {return x % 2 == 0; });
    displayVec(vec1);
    displayVec(vec2);
}

void vecTransform()
{
    std::cout << "\n===================================" << std::endl;
    std::cout << "-----Vector Transform Function-----" << std::endl;

    std::vector<int> vec1{ 1, 2, 3, 4, 5 };
    std::vector<int> vec2{ 10, 20, 30, 40 ,50 };
    std::vector<int> vec3;

    std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(vec3), [](int x, int y) {return x * y; });

    displayVec(vec3);
}

void vecFindAndInsert()
{
    std::cout << "\n==========================================" << std::endl;
    std::cout << "-----Vector Find and Insert Functions-----" << std::endl;

    std::vector<int> vec1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> vec2{ 100, 200, 300, 400, 500 };

    displayVec(vec1);
    displayVec(vec2);
    std::cout << std::endl;

    auto it = std::find(vec1.begin(), vec1.end(), 5);
    if (it != vec1.end())
    {
        std::cout << "Inserting" << std::endl;
        vec1.insert(it, vec2.begin(), vec2.end());
    }
    else
    {
        std::cout << "5 not Found" << std::endl;
    }
    displayVec(vec1);
}