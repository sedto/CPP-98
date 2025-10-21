/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:45:31 by dibsejra          #+#    #+#             */
/*   Updated: 2025/10/21 13:06:14 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

class Contact
{
	private:
	
	// _ mean is private
	// can't modify directly so we forced to use the getters/setters to read or change values.
	// so we can add some security check on the input user.
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phone;
	std::string _darkestSecret;

	public:

	//getters : to read the value
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhone(void) const;
	std::string getDarkestSecret(void) const;

	//setters: to modify values
	void setFirstName(std::string fn);
	void setLastName(std::string fn);
	void setNickname(std::string fn);
	void setPhone(std::string fn);
	void setDarkestSecret(std::string fn);

};

class PhoneBook
{
	private:
	Contact _contact[8];
	int _index;

	public:
	PhoneBook();
	void addContact (Contact c);
	Contact getContact(int idx);
	int getContactCount(void) const;
};
