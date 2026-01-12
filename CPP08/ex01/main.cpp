/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:46:10 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:46:11 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::cout << "=== Test 1: Basic test from subject ===" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Try to add too many numbers ===" << std::endl;
	try
	{
		Span sp = Span(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4); // Should throw
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Not enough numbers ===" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(1);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Empty span ===" << std::endl;
	try
	{
		Span sp = Span(5);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Large span (10,000 numbers) ===" << std::endl;
	try
	{
		Span sp = Span(10000);

		std::srand(std::time(0));
		for (int i = 0; i < 10000; i++)
		{
			sp.addNumber(std::rand());
		}

		std::cout << "Added 10,000 numbers" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Using range of iterators ===" << std::endl;
	try
	{
		Span sp = Span(10);
		std::vector<int> vec;

		for (int i = 0; i < 10; i++)
		{
			vec.push_back(i * 10);
		}

		sp.addRange(vec.begin(), vec.end());

		std::cout << "Added numbers using range" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Negative numbers ===" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(-100);
		sp.addNumber(-50);
		sp.addNumber(0);
		sp.addNumber(50);
		sp.addNumber(100);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
