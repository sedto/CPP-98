/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:13:13 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:16:57 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form(void)
{
}

const std::string& Form::getName(void) const
{
	return this->_name;
}

bool Form::isSigned(void) const
{
	return this->_signed;
}

int Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName()
	   << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute();
	return os;
}