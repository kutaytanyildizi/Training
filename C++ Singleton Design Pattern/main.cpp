#include<iostream>

//Ensure a class only has one instance, and provide a global point of access to it. 

/*
1) Singleton is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.
2) One of the most common reasons for wanting a single instance of the class is to control access to some shared resource, such as a database or file.
   There is a another side to want a single instance of the class you don't want the code that solves problem #1 to be scratted all over your program. 
3) Imagine that you created an object, but after a while decided to create a new one. Instead of receiving a fresh object, you’ll get the one you already created.
*/

class Singleton
{
private:
    Singleton() = default;
    int data;
    friend std::ostream &operator<<(std::ostream &os, const Singleton &sngl)
    {
        os << Singleton::getInstance().getData();
        return os; 
    }

public:
    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
    int getData() const
    {
        return data;
    }
    void setData(int data)
    {
        this->data = data;
    }
};

int main()
{
    Singleton& singleton1 = Singleton::getInstance();
    singleton1.setData(20);
    std::cout << "Singleton 1 Data = " << singleton1 << std::endl;
    Singleton& singleton2 = Singleton::getInstance();
    std::cout << "Singleton 2 Data = " << singleton2 << std::endl;
    Singleton::getInstance().setData(50);
    std::cout << "Singleton 1 Data = " << singleton1 << std::endl;
    std::cout << "Singleton 2 Data = " << singleton2 << std::endl;
}