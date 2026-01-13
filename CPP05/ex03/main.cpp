/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:13:55 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/13 20:02:13 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	std::cout << "\nTest 1: Intern creates ShrubberyCreationForm" << std::endl;
	try {
		Intern intern;
		Bureaucrat bob("Bob", 137);
		AForm* shrub = intern.makeForm("shrubbery creation", "home");

		std::cout << *shrub << std::endl;
		bob.signForm(*shrub);
		bob.executeForm(*shrub);
		delete shrub;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 2: Intern creates RobotomyRequestForm" << std::endl;
	try {
		Intern intern;
		Bureaucrat charlie("Charlie", 40);
		AForm* robot = intern.makeForm("robotomy request", "Bender");

		std::cout << *robot << std::endl;
		charlie.signForm(*robot);
		charlie.executeForm(*robot);
		delete robot;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 3: Intern creates PresidentialPardonForm" << std::endl;
	try {
		Intern intern;
		Bureaucrat president("President", 1);
		AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");

		std::cout << *pardon << std::endl;
		president.signForm(*pardon);
		president.executeForm(*pardon);
		delete pardon;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 4: Intern with invalid form name" << std::endl;
	try {
		Intern intern;
		AForm* invalid = intern.makeForm("invalid form", "target");
		delete invalid;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTest 5: Multiple interns creating different forms" << std::endl;
	try {
		Intern intern1;
		Intern intern2;
		Intern intern3;
		Bureaucrat boss("Boss", 1);

		AForm* form1 = intern1.makeForm("shrubbery creation", "garden");
		AForm* form2 = intern2.makeForm("robotomy request", "Leblanc");
		AForm* form3 = intern3.makeForm("presidential pardon", "Teemo");

		boss.signForm(*form1);
		boss.executeForm(*form1);

		std::cout << std::endl;
		boss.signForm(*form2);
		boss.executeForm(*form2);

		std::cout << std::endl;
		boss.signForm(*form3);
		boss.executeForm(*form3);

		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}