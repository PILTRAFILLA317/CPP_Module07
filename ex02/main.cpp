#include <iostream>
#include "Array.hpp"

#define MAX_VAL 50
int main(int, char**)
{
	Array<int> empty;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = i;
		numbers[i] = value;
		mirror[i] = value;
	}
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	std::cout << "numbers: " << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << numbers[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << "mirror: " << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << mirror[i] << ", ";
	}
	std::cout << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		std::cout << "Debería tirar un error: " << std::endl;
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "------------" << std::endl;
	}
	try
	{
		std::cout << "Debería tirar un error: " << std::endl;
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "------------" << std::endl;
	}
	try
	{
		std::cout << "Debería imprimir el ultimo numero: " << std::endl;
		std::cout << numbers[MAX_VAL - 1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "------------" << std::endl;
	}
	delete [] mirror;
	return 0;
}
