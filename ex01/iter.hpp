#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, int length, void (*funct)(T item))
{
	for (int i = 0; i < length; i++)
		funct(array[i]);
};

#endif