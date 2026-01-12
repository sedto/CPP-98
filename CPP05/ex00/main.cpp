/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:12:48 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:12:52 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	std::cout << "=== Test 1: Valid bureaucrat creation ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment grade ===" << std::endl;
	try {
		Bureaucrat dave("Dave", 2);
		std::cout << dave << std::endl;
		dave.incrementGrade();
		std::cout << dave << std::endl;
		dave.incrementGrade(); // This should throw
		std::cout << dave << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement grade ===" << std::endl;
	try {
		Bureaucrat eve("Eve", 149);
		std::cout << eve << std::endl;
		eve.decrementGrade();
		std::cout << eve << std::endl;
		eve.decrementGrade(); // This should throw
		std::cout << eve << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Copy constructor ===" << std::endl;
	try {
		Bureaucrat frank("Frank", 50);
		Bureaucrat frankCopy(frank);
		std::cout << "Original: " << frank << std::endl;
		std::cout << "Copy: " << frankCopy << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Assignment operator ===" << std::endl;
	try {
		Bureaucrat grace("Grace", 100);
		Bureaucrat henry("Henry", 50);
		std::cout << "Before assignment:" << std::endl;
		std::cout << grace << std::endl;
		std::cout << henry << std::endl;
		grace = henry;
		std::cout << "After assignment:" << std::endl;
		std::cout << grace << std::endl; // Grade changes but name stays "Grace"
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}