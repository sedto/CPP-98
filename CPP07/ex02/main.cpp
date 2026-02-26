/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:37:05 by dibsejra          #+#    #+#             */
/*   Updated: 2026/02/26 12:44:18 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "Test 1: Empty array" << std::endl;
	try
	{
		Array<int> empty;
		std::cout << "Empty array size: " << empty.size() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 2: Array of integers" << std::endl;
	try
	{
		Array<int> numbers(5);
		std::cout << "Array size: " << numbers.size() << std::endl;

		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			numbers[i] = i * 10;
		}

		std::cout << "Array contents: ";
		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 3: Copy constructor" << std::endl;
	try
	{
		Array<int> original(3);
		original[0] = 1;
		original[1] = 2;
		original[2] = 3;

		Array<int> copy(original);

		std::cout << "Original: ";
		for (unsigned int i = 0; i < original.size(); i++)
			std::cout << original[i] << " ";
		std::cout << std::endl;

		std::cout << "Copy: ";
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << " ";
		std::cout << std::endl;

		copy[0] = 99;
		std::cout << "After modifying copy[0] to 99:" << std::endl;
		std::cout << "Original[0]: " << original[0] << std::endl;
		std::cout << "Copy[0]: " << copy[0] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 4: Assignment operator" << std::endl;
	try
	{
		Array<int> a(3);
		a[0] = 10;
		a[1] = 20;
		a[2] = 30;

		Array<int> b;
		b = a;

		std::cout << "Array a: ";
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;

		std::cout << "Array b: ";
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << b[i] << " ";
		std::cout << std::endl;

		b[1] = 999;
		std::cout << "After modifying b[1] to 999:" << std::endl;
		std::cout << "Array a[1]: " << a[1] << std::endl;
		std::cout << "Array b[1]: " << b[1] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 5: Out of bounds exception" << std::endl;
	try
	{
		Array<int> test(5);
		std::cout << "Accessing valid index 4: " << test[4] << std::endl;
		std::cout << "Trying to access invalid index 5..." << std::endl;
		std::cout << test[5] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nTest 6: Array of strings" << std::endl;
	try
	{
		Array<std::string> strings(3);
		strings[0] = "Hello";
		strings[1] = "World";
		strings[2] = "!";

		std::cout << "String array: ";
		for (unsigned int i = 0; i < strings.size(); i++)
		{
			std::cout << strings[i] << " ";
		}
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 7: Array of doubles" << std::endl;
	try
	{
		Array<double> doubles(4);
		for (unsigned int i = 0; i < doubles.size(); i++)
		{
			doubles[i] = i * 1.5;
		}

		std::cout << "Double array: ";
		for (unsigned int i = 0; i < doubles.size(); i++)
		{
			std::cout << doubles[i] << " ";
		}
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
