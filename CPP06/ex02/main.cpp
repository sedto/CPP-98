/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:32:35 by dibsejra          #+#    #+#             */
/*   Updated: 2026/02/26 12:41:37 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void)
{
	std::cout << "Test 1: Random generation" << std::endl;
	Base* random = generate();
	std::cout << "Identify with pointer: ";
	identify(random);
	std::cout << "Identify with reference: ";
	identify(*random);
	delete random;

	std::cout << "\nTest 2: All types" << std::endl;
	Base* a = new A();
	Base* b = new B();
	Base* c = new C();

	std::cout << "Type A (pointer): ";
	identify(a);
	std::cout << "Type A (reference): ";
	identify(*a);

	std::cout << "Type B (pointer): ";
	identify(b);
	std::cout << "Type B (reference): ";
	identify(*b);

	std::cout << "Type C (pointer): ";
	identify(c);
	std::cout << "Type C (reference): ";
	identify(*c);

	delete a;
	delete b;
	delete c;

	return 0;
}
