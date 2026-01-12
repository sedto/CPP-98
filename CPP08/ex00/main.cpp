/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:40:05 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:40:06 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
	std::cout << "=== Test 1: Vector ===" << std::endl;
	try
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found: " << *it << std::endl;

		it = easyfind(vec, 10);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: List ===" << std::endl;
	try
	{
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);
		lst.push_back(50);

		std::list<int>::iterator it = easyfind(lst, 30);
		std::cout << "Found: " << *it << std::endl;

		it = easyfind(lst, 100);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Deque ===" << std::endl;
	try
	{
		std::deque<int> deq;
		deq.push_back(100);
		deq.push_back(200);
		deq.push_back(300);
		deq.push_back(400);

		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Found: " << *it << std::endl;

		it = easyfind(deq, 500);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Empty container ===" << std::endl;
	try
	{
		std::vector<int> empty;
		std::vector<int>::iterator it = easyfind(empty, 1);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: First element ===" << std::endl;
	try
	{
		std::vector<int> vec;
		vec.push_back(42);
		vec.push_back(43);
		vec.push_back(44);

		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Last element ===" << std::endl;
	try
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(999);

		std::vector<int>::iterator it = easyfind(vec, 999);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}