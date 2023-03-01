#include <iostream>
#include <queue>
// std::priority queue
// Allows insertions and removal of elements in oreder from the front of the container
// Elements are stored internally as a vector by default
// No iterators are supported
// Elements are inserted in priority order (Largest value will always be at the front)
/*
push  - insert an element intý sorted order
pop   - removes the top element(greatest)
top   - access the top element(greatest)
empty - returns true if queue is empty
size  - number of elements in the queue
*/

class Person
{
private:
    friend std::ostream& operator<<(std::ostream& os, const Person& prs)
    {
        os << prs.name << ":" << prs.age;
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
        if ((rhs.name == name) && (rhs.age == age))
        {
            return true;
        }
        return false;
    }
};

template<typename T>
void displayPriorityQueue(std::priority_queue<T> pq)
{
    std::cout << "[ ";
    while (!(pq.empty()))
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "]" << std::endl;
}

int main()
{

    std::priority_queue<int> pq;
    for (int i : {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7})
    {
        pq.push(i);
    }

    std::cout << "Size : " << pq.size() << std::endl;
    std::cout << "Top : " << pq.top() << std::endl;
    displayPriorityQueue(pq);

    pq.pop();
    displayPriorityQueue(pq);

    std::priority_queue<Person> ppq;
    ppq.push(Person{ "A", 10 });
    ppq.push(Person{ "B", 1 });
    ppq.push(Person{ "C", 14 });
    ppq.push(Person{ "D", 18 });
    ppq.push(Person{ "E", 7 });
    ppq.push(Person{ "F", 27 });

    displayPriorityQueue(ppq);

    return 0;
}