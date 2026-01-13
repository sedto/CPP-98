/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:13:25 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:13:26 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "\nTest 1: Valid form creation" << std::endl;
	try {
		Form form1("Tax Form", 50, 25);
		std::cout << form1 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 2: Form with grade too high" << std::endl;
	try {
		Form form2("Invalid Form", 0, 50);
		std::cout << form2 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 3: Form with grade too low" << std::endl;
	try {
		Form form3("Invalid Form", 50, 151);
		std::cout << form3 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 4: Successful form signing" << std::endl;
	try {
		Bureaucrat alice("Alice", 30);
		Form form4("Building Permit", 50, 25);
		std::cout << form4 << std::endl;
		alice.signForm(form4);
		std::cout << form4 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 5: Failed form signing (grade too low)" << std::endl;
	try {
		Bureaucrat bob("Bob", 100);
		Form form5("Top Secret", 50, 25);
		std::cout << form5 << std::endl;
		bob.signForm(form5);
		std::cout << form5 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 6: Multiple bureaucrats signing" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 10);
		Bureaucrat dave("Dave", 60);
		Form form6("License", 50, 30);

		std::cout << form6 << std::endl;
		dave.signForm(form6); // Should fail
		charlie.signForm(form6); // Should succeed
		std::cout << form6 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 7: Signing already signed form" << std::endl;
	try {
		Bureaucrat eve("Eve", 20);
		Form form7("Passport", 40, 20);

		eve.signForm(form7);
		eve.signForm(form7); // Sign again
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}