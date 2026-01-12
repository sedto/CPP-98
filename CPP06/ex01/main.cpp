/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:31:15 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:31:16 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data originalData;
	originalData.name = "Test Data";
	originalData.value = 42;
	originalData.price = 19.99;

	std::cout << "Original Data:" << std::endl;
	std::cout << "  Address: " << &originalData << std::endl;
	std::cout << "  Name: " << originalData.name << std::endl;
	std::cout << "  Value: " << originalData.value << std::endl;
	std::cout << "  Price: " << originalData.price << std::endl;
	std::cout << std::endl;

	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized: " << serialized << std::endl;
	std::cout << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "  Address: " << deserialized << std::endl;
	std::cout << "  Name: " << deserialized->name << std::endl;
	std::cout << "  Value: " << deserialized->value << std::endl;
	std::cout << "  Price: " << deserialized->price << std::endl;
	std::cout << std::endl;

	if (deserialized == &originalData)
		std::cout << "Success! Pointers are equal." << std::endl;
	else
		std::cout << "Error! Pointers are different." << std::endl;

	return 0;
}
