/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:15:10 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 13:15:11 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
	std::cout << "=== Test 1: Basic test from subject ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n=== Test 2: Same test with std::list ===" << std::endl;
	{
		std::list<int> mlist;

		mlist.push_back(5);
		mlist.push_back(17);

		std::cout << "Back: " << mlist.back() << std::endl;

		mlist.pop_back();

		std::cout << "Size: " << mlist.size() << std::endl;

		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n=== Test 3: Copy constructor ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(10);
		mstack.push(20);
		mstack.push(30);

		MutantStack<int> copy(mstack);

		std::cout << "Original stack: ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Copied stack: ";
		for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 4: Assignment operator ===" << std::endl;
	{
		MutantStack<int> mstack1;
		mstack1.push(1);
		mstack1.push(2);
		mstack1.push(3);

		MutantStack<int> mstack2;
		mstack2.push(100);
		mstack2.push(200);

		std::cout << "Before assignment - Stack2: ";
		for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		mstack2 = mstack1;

		std::cout << "After assignment - Stack2: ";
		for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 5: Reverse iterators ===" << std::endl;
	{
		MutantStack<int> mstack;
		for (int i = 1; i <= 5; i++)
		{
			mstack.push(i * 10);
		}

		std::cout << "Forward: ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Reverse: ";
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 6: String stack ===" << std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("Hello");
		mstack.push("World");
		mstack.push("42");

		std::cout << "String stack: ";
		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Top: " << mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
	}

	std::cout << "\n=== Test 7: Empty stack ===" << std::endl;
	{
		MutantStack<int> mstack;

		std::cout << "Is empty: " << (mstack.empty() ? "yes" : "no") << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push(42);
		std::cout << "After push - Is empty: " << (mstack.empty() ? "yes" : "no") << std::endl;
		std::cout << "After push - Size: " << mstack.size() << std::endl;
	}

	return 0;
}
