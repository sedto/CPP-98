/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:13:34 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:26:58 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

AForm::~AForm(void)
{
}

const std::string& AForm::getName(void) const
{
	return this->_name;
}

bool AForm::isSigned(void) const
{
	return this->_signed;
}

int AForm::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form " << form.getName()
	   << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute();
	return os;
}
