/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:46:00 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:46:01 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

	Span(void);

public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span(void);

	void addNumber(int number);

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			addNumber(*begin);
			++begin;
		}
	}

	int shortestSpan(void) const;
	int longestSpan(void) const;

	class FullException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};
};

#endif
