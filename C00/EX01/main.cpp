/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:18:28 by dibsejra          #+#    #+#             */
/*   Updated: 2025/10/21 19:28:10 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <sstream>
#include <cstdlib>

std::string formatColumn(std::string str)
{
    const int WIDTH = 10;
    
    if (str.length() > WIDTH)
    {
        return str.substr(0, WIDTH - 1) + ".";
    }
    std::string padded(WIDTH - str.length(), ' ');
    return padded + str;
}
void searchContactMode(PhoneBook &pb)
{
    if (pb.getContactCount() == 0)
    {
        std::cout << "No contacts!" << std::endl;
        return;
    }
    
    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    
    for (int i = 0; i < pb.getContactCount(); i++)
    {
        Contact c = pb.getContact(i);

        std::stringstream ss;
        ss << (i + 1);
        std::cout << formatColumn(ss.str()) << "|";
        std::cout << formatColumn(c.getFirstName()) << "|";
        std::cout << formatColumn(c.getLastName()) << "|";
        std::cout << formatColumn(c.getNickname()) << std::endl;
    }
    
    std::string input;
    std::cout << "? Enter index: ";
    std::getline(std::cin, input);
    
    if (input.empty())
    {
        std::cout << "Error: Invalid index!" << std::endl;
        return;
    }
    
    int idx = atoi(input.c_str());

    if (idx < 1 || idx > pb.getContactCount())
    {
        std::cout << "Error: Invalid index!" << std::endl;
        return;
    }
    
    Contact c = pb.getContact(idx - 1);
    std::cout << "First name: " << c.getFirstName() << std::endl;
    std::cout << "Last name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone number: " << c.getPhone() << std::endl;
    std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}


// Check Phone Number
static bool isValidPhone(std::string phone)
{
    if (phone.empty())
        return false;
    for (size_t i = 0; i < phone.length(); ++i)
    {
        if (!std::isdigit(phone[i]))
            return false;
    }
    return true;
}
// Adding a contact infos
void addContactMode(PhoneBook &pb)
{
	Contact newContact;
	std::string input;

	while(1)
	{
		std::cout << "First name ?\t";
		std::getline(std::cin, input);

		if (input.empty())
		{
			continue;
		}
		newContact.setFirstName(input);
		break;
	}
	while(1)
	{
		std::cout << "Last name ?\t";
		std::getline(std::cin, input);
		
		if(input.empty())
		{
			continue;
		}
		newContact.setLastName(input);
		break;
	}
	while(1)
	{
		std::cout << "Nickname ?\t";
		std::getline(std::cin, input);
		
		if(input.empty())
		{
			continue;
		}
		newContact.setNickname(input);
		break;
	}
	while(1)
	{
		std::cout << "Phone ?\t";
		std::getline(std::cin, input);
		
		if(input.empty() || !isValidPhone(input))
		{
			std::cout << "Invalid phone number use only 0 - 9\n";
			continue;
		}
		newContact.setPhone(input);
		break;
	}
	while(1)
	{
		std::cout << "Darkest Secret?\t";
		std::getline(std::cin, input);
		
		if(input.empty())
		{
			continue;
		}
		newContact.setDarkestSecret(input);
		break;
	}
	pb.addContact(newContact);
}

int main(void)
{
	PhoneBook pb;
	std::string command;

	while (1)
	{
		std::cout << "[phonebook] >";
		std::getline(std::cin, command);
	
		if (command == "add" || command == "ADD")
		{
			addContactMode(pb);
		}
		else if (command == "search" || command == "SEARCH")
		{
			searchContactMode(pb);
		}
		else if (command == "exit" || command == "EXIT")
		{
			break;
		}
	}
	return 0;
}