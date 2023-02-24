#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>  

template<typename T>
void displayDeq(const std::deque<T>& deq)
{
    std::cout << "[";
    for (const auto it : deq)
    {
        std::cout << it << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{   
    std::deque<int> d{ 1, 2, 3, 4, 5 };
    displayDeq(d);
    std::cout << std::endl;

    d[0] = 100;
    d.at(1) = 200;
    displayDeq(d);
    std::cout << std::endl;

    std::deque<int> d1 (10,100);
    displayDeq(d1);
    std::cout << std::endl;

    d.push_back(10);
    d.push_back(50);
    d.push_front(90);
    d.push_front(47);
    displayDeq(d);
    std::cout << "Front : " << d.front() << std::endl;
    std::cout << "Back : " << d.back() << std::endl;
    std::cout << "Size : " << d.size() << std::endl;
    std::cout << std::endl;

    d.pop_back();
    d.pop_front();
    displayDeq(d);
    std::cout << std::endl;

    std::vector<int> vec{ 1 ,2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::deque<int> deq;

    for (const auto elem : vec)
    {
        if (elem % 2 == 0)
        {
            deq.push_back(elem);
        }
        else
        {
            deq.push_front(elem);
        }
    }
    displayDeq(deq);
    std::cout << std::endl;

    deq.clear();
    for (const auto elem : vec)
    {
        deq.push_front(elem);
    }
    displayDeq(deq);
    std::cout << std::endl;

    deq.clear();
    std::copy(vec.begin(), vec.end(), std::front_inserter(deq));
    displayDeq(deq);
    std::cout << std::endl;;

    deq.clear();
    std::copy(vec.begin(), vec.end(), std::back_inserter(deq));
    displayDeq(deq);

 	return 0;
}