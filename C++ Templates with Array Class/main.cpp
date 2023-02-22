#include <iostream>
#include <string>

template<typename T,int N>
class Array
{
private:
	int size {N};
	T values[N];
	friend std::ostream& operator<<(std::ostream& os, const Array<T,N>& arr)
	{
		os << "[";
		for (const auto& val : arr.values)
		{
			os << val << " ";
		}
		os << "]";
		return os;
	}

public:
	Array() = default;
	Array(T initValue)
	{
		for (auto& item : values)
		{
			item = initValue;
		}
	}
	
	void fill(T val)
	{
		for (auto& item : values)
		{
			item = val;
		}
	}

	int getSize() const
	{
		return size;
	}

	T& operator[](int index)
	{
		return values[index];
	}
};

int main()
{
	Array<int, 5> nums;
	std::cout << "The size of nums is: " << nums.getSize() << std::endl;
	std::cout << nums << std::endl;

	nums.fill(0);
	std::cout << "The size of nums is: " << nums.getSize() << std::endl;
	std::cout << nums << std::endl;

	nums.fill(10);
	std::cout << "The size of nums is: " << nums.getSize() << std::endl;
	std::cout << nums << std::endl;

	nums[0] = 100;
	nums[3] = 300;
	std::cout << nums << std::endl;

	Array<int, 100> nums2{ 1 };
	std::cout << "The size of nums2 is: " << nums2.getSize() << std::endl;
	std::cout << nums2 << std::endl;
	
	Array<std::string, 10> strings(std::string{ "Kutay" });
	std::cout << "The size of strings is: " << strings.getSize() << std::endl;
	std::cout << strings << std::endl;

	return 0;
}

