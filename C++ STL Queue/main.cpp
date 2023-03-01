#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue> // (FÝFO) First in First out
// We can't use queues with STL Algorithms
// No iterators supported
/*
push  - insert an element at the back of the queue
pop   - remove an element from the front of the queue
front - returns the front element of the queue
back  - returns the back element of the queue
empty - returns true if the queue is empty
size  - returns the number of elements in the queue
*/
// Queue is adapter container, we can choose underlying container will be used when we create our queue objects. (STL will use deque by default)

template<typename T>
void displayQueue(std::queue<T> q)
{
	std::cout << "[ ";
	while (!(q.empty()))
	{
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << "]" << std::endl;
}

int main()
{
	std::queue<int> q;
	std::queue<int, std::list<int>> q1;
	std::queue<int, std::vector<int>> q2;
	std::queue<int, std::deque<int>> q3;

	for (int i : {1, 10, 100, 1000, 10000})
	{
		q.push(i);
	}
	displayQueue(q);
	
	std::cout << "Front : " << q.front() << std::endl;
	std::cout << "Back : " << q.back() << std::endl;

	q.push(100);
	displayQueue(q);

	q.pop();
	q.pop();
	displayQueue(q);

	while (!(q.empty()))
	{
		q.pop();
	}

	std::cout << "Size : " << q.size() << std::endl;

	q.push(10);
	q.push(100);
	q.push(1000);
	displayQueue(q);

	std::cout << "Front : " << q.front() << std::endl;
	std::cout << "Back : " << q.back() << std::endl;

	q.front() = 5;
	q.back() = 5000;

	std::cout << "Front : " << q.front() << std::endl;
	std::cout << "Back : " << q.back() << std::endl;

	return 0;
}

