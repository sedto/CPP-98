/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:01:35 by dibsejra          #+#    #+#             */
/*   Updated: 2025/12/04 16:01:36 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "=== Testing correct polymorphism ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nType: " << j->getType() << std::endl;
	std::cout << "Type: " << i->getType() << std::endl;

	std::cout << "\nSounds:" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n=== Deleting animals ===" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n=== Testing WRONG polymorphism ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\nType: " << wrongCat->getType() << std::endl;

	std::cout << "\nSounds:" << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << "\n=== Deleting wrong animals ===" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	return 0;
}