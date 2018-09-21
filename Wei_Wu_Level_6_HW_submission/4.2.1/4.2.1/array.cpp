#ifndef Array_CPP
#define Array_CPP

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Point.hpp"
#include "array.hpp"
#include <sstream>
#include "circle.hpp"
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;
template<typename T>
Array<T>::Array()
{
	m_data = new T[10];
	m_size = 10;
}

template<typename T>
Array<T>::Array(const int& nSize)
{
	m_size = nSize;
	m_data = new T[m_size];
	//Point* array[size];
	cout << "construct array class\n";
}

//copy constructor
template<typename T>
Array<T>::Array(const Array& a)
{
	m_data = new T[a.m_size];
	m_size = a.m_size;
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = a.m_data[i];
	}
}


//assignment constructor
template<typename T>
Array<T>& Array<T>::operator = (const Array& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	delete[] m_data;					//delete the old C array 
	m_data = new T[source.m_size];	// allocate new memory before copying the elements
	m_size = source.m_size;
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = source.m_data[i];
	}

	return *this;
}

//return size of array class
template<typename T>
int Array<T>::Size() const
{
	return m_size;
}

template<typename T>
void Array<T>::SetElement(const int& index, const T& p)	//index starts from 0
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	} else
	m_data[index] = p;
}

template<typename T>
T Array<T>::GetElement(const int& index) const
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	} else
	return m_data[index];		//return by reference.
}

template<typename T>
bool Array<T>::operator == (const Array& a) const // Equally compare operator.
{
	if (a.m_size == m_size)
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_data[i] != a.m_data[i])
			{
				return 0;
			}
		}
		return 1;
	}
	else return 0;
}


template<typename T>
T& Array<T>::operator [] (int index) // Assignment operator.
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	} else
	return m_data[index];
}

//If the Point type is known to be a built-in type, the const variant should return by value.
template<typename T>
const T& Array<T>::operator [] (int index) const// Assignment operator.
{
	if (index < 0 || index >= Size())
	{
		throw OutOfBoundsException(index);
	} else
	return m_data[index];
}


#endif