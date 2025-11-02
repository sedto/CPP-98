/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:00:00 by dibsejra          #+#    #+#             */
/*   Updated: 2025/10/29 16:00:00 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "=== Creating ClapTrap ===" << std::endl;
	ClapTrap clap("Bob");
	std::cout << std::endl;

	std::cout << "=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("Alice");
	std::cout << std::endl;

	std::cout << "=== Creating FragTrap ===" << std::endl;
	FragTrap frag("Charlie");
	std::cout << std::endl;

	std::cout << "=== Testing ClapTrap ===" << std::endl;
	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);
	std::cout << std::endl;

	std::cout << "=== Testing ScavTrap ===" << std::endl;
	scav.attack("enemy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	std::cout << std::endl;

	std::cout << "=== Testing FragTrap ===" << std::endl;
	frag.attack("monster");
	frag.takeDamage(50);
	frag.beRepaired(25);
	frag.highFivesGuys();
	std::cout << std::endl;

	std::cout << "=== Destruction (reverse order) ===" << std::endl;
	return 0;
}