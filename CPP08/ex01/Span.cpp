/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:46:05 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:46:06 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

Span::Span(void) : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(const Span& other) : _maxSize(0)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_maxSize = other._maxSize;
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span(void)
{
}

void Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_maxSize)
		throw FullException();
	this->_numbers.push_back(number);
}

int Span::shortestSpan(void) const
{
	if (this->_numbers.size() <= 1)
		throw NoSpanException();

	std::vector<int> sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}

	return minSpan;
}

int Span::longestSpan(void) const
{
	if (this->_numbers.size() <= 1)
		throw NoSpanException();

	int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());

	return max - min;
}

const char* Span::FullException::what(void) const throw()
{
	return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what(void) const throw()
{
	return "Not enough numbers to calculate span";
}
