#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
		T *arr;
		unsigned int size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array &operator=(const Array &other);
		T &operator[](unsigned int i);
		unsigned int getSize() const;
		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <typename T>
Array<T>::Array()
{
	this->arr = NULL;
	this->size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr = new T[n];
	this->size = n;
}

template <typename T>
Array<T>::Array(const Array &other)
{
	this->arr = new T[other.size];
	this->size = other.size;
	for (unsigned int i = 0; i < this->size; i++)
		this->arr[i] = other.arr[i];
}

template <typename T>
Array<T>::~Array()
{
	if (this->arr)
		delete[] this->arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this->arr)
		delete[] this->arr;
	this->arr = new T[other.size];
	this->size = other.size;
	for (unsigned int i = 0; i < this->size; i++)
		this->arr[i] = other.arr[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->size)
		throw Array::OutOfRangeException();
	return (this->arr[i]);
}

template <typename T>
unsigned int Array<T>::getSize() const
{
	return (this->size);
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
	return ("Tas pasado rey");
}

#endif