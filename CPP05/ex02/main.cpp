/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:13:55 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/13 19:50:26 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << " Test 1: ShrubberyCreationForm" << std::endl;
	try {
		Bureaucrat bob("Bob", 137);
		ShrubberyCreationForm shrub("home");

		std::cout << shrub << std::endl;
		bob.signForm(shrub);
		bob.executeForm(shrub);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 2: ShrubberyCreationForm - Failed execution (not signed)" << std::endl;
	try {
		Bureaucrat alice("Alice", 100);
		ShrubberyCreationForm shrub2("garden");

		alice.executeForm(shrub2);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n Test 3: RobotomyRequestForm" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 40);
		RobotomyRequestForm robot("Bender");

		std::cout << robot << std::endl;
		charlie.signForm(robot);
		charlie.executeForm(robot);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n Test 4: RobotomyRequestForm - Multiple executions" << std::endl;
	try {
		Bureaucrat dave("Dave", 1);
		RobotomyRequestForm robot2("Marvin");

		dave.signForm(robot2);
		for (int i = 0; i < 5; i++) {
			std::cout << "\nAttempt " << (i + 1) << ":" << std::endl;
			dave.executeForm(robot2);
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n Test 5: PresidentialPardonForm" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n Test 6: PresidentialPardonForm - Grade too low to sign" << std::endl;
	try {
		Bureaucrat lowGrade("LowGrade", 30);
		PresidentialPardonForm pardon2("Ford Prefect");

		lowGrade.signForm(pardon2);
		lowGrade.executeForm(pardon2);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 7: PresidentialPardonForm - Grade too low to execute" << std::endl;
	try {
		Bureaucrat signer("Signer", 20);
		Bureaucrat executor("Executor", 10);
		PresidentialPardonForm pardon3("Zaphod");

		signer.signForm(pardon3);
		executor.executeForm(pardon3); // Should fail
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 8: All forms with highest bureaucrat" << std::endl;
	try {
		Bureaucrat supreme("Supreme", 1);
		ShrubberyCreationForm shrub("office");
		RobotomyRequestForm robot("C-3PO");
		PresidentialPardonForm pardon("Trillian");

		supreme.signForm(shrub);
		supreme.executeForm(shrub);

		std::cout << std::endl;
		supreme.signForm(robot);
		supreme.executeForm(robot);

		std::cout << std::endl;
		supreme.signForm(pardon);
		supreme.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}