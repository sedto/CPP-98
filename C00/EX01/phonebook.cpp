/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:59:00 by dibsejra          #+#    #+#             */
/*   Updated: 2025/10/21 18:31:10 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// setters:
void Contact::setFirstName(std::string fn)
{
	this->_firstName = fn;
}
void Contact::setLastName(std::string fn)
{
	this->_lastName = fn;
}
void Contact::setNickname(std::string fn)
{
	this->_nickname = fn;
}
void Contact::setPhone(std::string fn)
{
	this->_phone = fn;
}
void Contact::setDarkestSecret(std::string fn)
{
	this->_darkestSecret = fn;
}

// getters:
std::string Contact::getFirstName(void) const
{
	return this->_firstName;
}

std::string Contact::getLastName(void) const
{
	return this->_lastName;
}

std::string Contact::getNickname(void) const
{
	return this->_nickname;
}

std::string Contact::getPhone(void) const
{
	return this->_phone;
}

std::string Contact::getDarkestSecret(void) const
{
	return this->_darkestSecret;
}


PhoneBook::PhoneBook()
{
	this->_index = 0;
}

Contact PhoneBook::getContact(int idx)
{
	return this->_contact[idx];
}
void PhoneBook::addContact(Contact c)
{
	this->_contact[this->_index % 8] = c;
	this->_index++;
}
int PhoneBook::getContactCount(void) const
{
	if (this->_index >= 8)
		return 8;
	return this->_index;
}
