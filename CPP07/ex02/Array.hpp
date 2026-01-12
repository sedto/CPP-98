/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:37:00 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:37:01 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
private:
	T*				_array;
	unsigned int	_size;

public:
	Array(void);
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array(void);

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	unsigned int size(void) const;

	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};
};

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		if (this->_array)
			delete[] this->_array;

		this->_size = other._size;
		if (other._size > 0)
		{
			this->_array = new T[other._size]();
			for (unsigned int i = 0; i < other._size; i++)
			{
				this->_array[i] = other._array[i];
			}
		}
		else
		{
			this->_array = NULL;
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array(void)
{
	if (this->_array)
		delete[] this->_array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw OutOfBoundsException();
	return this->_array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw OutOfBoundsException();
	return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return this->_size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what(void) const throw()
{
	return "Index is out of bounds!";
}

#endif
