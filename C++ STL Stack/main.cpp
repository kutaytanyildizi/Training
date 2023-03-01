#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack> // (LÝFO) Last in First out
// We can't use stacks with STL Algorithms
// No iterators supported
/*
push  - insert an element at the top of the Stack
pop   - remove an element from the top of the Stack
top   - return the top element of the Stack
empty - return true if Stack is empty
size  - number of elements in the Stack
*/
// Stack is adapter container, we can choose underlying container will be used when we create our stack objects. (STL will use deque by default)

template<typename T>
void displayStack(std::stack<T> s)
{
	std::cout << "[ ";
	while(!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << "]" << std::endl;
}

int main()
{
	std::stack<int> s;
	std::stack<int, std::vector<int>> s1;
	std::stack<int, std::list<int>> s2;
	std::stack<int, std::deque<int>> s3;

	for (int i = 1; i < 6; i++)
	{
		s.push(i);
	}
	displayStack(s);

	s.push(100);
	displayStack(s);

	s.pop();
	s.pop();
	displayStack(s);

	while (!(s.empty()))
	{
		s.pop();
	}
	displayStack(s);

	std::cout << "Size : " << s.size() << std::endl;

	s.push(10);
	s.top() = 100;
	displayStack(s);

	return 0;
}

