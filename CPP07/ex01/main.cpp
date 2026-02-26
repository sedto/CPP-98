/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:36:05 by dibsejra          #+#    #+#             */
/*   Updated: 2026/02/26 12:43:12 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(T const & element)
{
	std::cout << element << std::endl;
}

template <typename T>
void incrementElement(T& element)
{
	element++;
}

void toUpperCase(std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = std::toupper(str[i]);
	}
}

int main(void)
{
	std::cout << "Test 1: Print int array" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	::iter(intArray, 5, printElement<int>);

	std::cout << "\nTest 2: Increment int array" << std::endl;
	::iter(intArray, 5, incrementElement<int>);
	std::cout << "After increment:" << std::endl;
	::iter(intArray, 5, printElement<int>);

	std::cout << "\nTest 3: Print string array" << std::endl;
	std::string stringArray[] = {"hello", "world", "cpp", "templates"};
	::iter(stringArray, 4, printElement<std::string>);

	std::cout << "\nTest 4: Convert to uppercase" << std::endl;
	::iter(stringArray, 4, toUpperCase);
	std::cout << "After uppercase conversion:" << std::endl;
	::iter(stringArray, 4, printElement<std::string>);

	std::cout << "\nTest 5: Print double array" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	::iter(doubleArray, 4, printElement<double>);

	std::cout << "\nTest 6: Increment double array" << std::endl;
	::iter(doubleArray, 4, incrementElement<double>);
	std::cout << "After increment:" << std::endl;
	::iter(doubleArray, 4, printElement<double>);

	return 0;
}
