/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:05:47 by dibsejra          #+#    #+#             */
/*   Updated: 2025/12/04 16:05:48 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::cout << "=== Test from subject ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << "\n=== Creating array of Animals ===" << std::endl;
	const int arraySize = 6;
	Animal* animals[arraySize];

	for (int idx = 0; idx < arraySize; idx++)
	{
		if (idx < arraySize / 2)
			animals[idx] = new Dog();
		else
			animals[idx] = new Cat();
	}

	std::cout << "\n=== Testing polymorphism ===" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
	{
		std::cout << animals[idx]->getType() << " says: ";
		animals[idx]->makeSound();
	}

	std::cout << "\n=== Deleting array of Animals ===" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
	{
		delete animals[idx];
	}

	std::cout << "\n=== Testing deep copy ===" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}

	return 0;
}