/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:16:46 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:16:47 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern(void)
{
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			for (int j = 0; j < 3; j++)
			{
				if (j != i)
					delete forms[j];
			}
			return forms[i];
		}
	}

	for (int i = 0; i < 3; i++)
		delete forms[i];

	std::cout << "Error: Form \"" << formName << "\" does not exist!" << std::endl;
	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what(void) const throw()
{
	return "Form not found!";
}