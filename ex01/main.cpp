#include "iter.hpp"

template <typename T>
void print(T i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	int int_array[5] = {1, 2, 3, 4, 5};
	std::string string_array[5] = {"one", "two", "three", "four", "five"};

	std::cout << "int array: " << std::endl;
	iter(int_array, 5, &print);
	std::cout << std::endl;
	std::cout << "string array: " << std::endl;
	iter(string_array, 5, &print);
	std::cout << std::endl;
	return 0;
}