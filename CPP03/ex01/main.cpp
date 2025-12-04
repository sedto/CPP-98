/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:00:00 by dibsejra          #+#    #+#             */
/*   Updated: 2025/12/04 09:20:45 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "Creating ClapTrap" << std::endl;
	ClapTrap clap("Bob");
	std::cout << std::endl;

	std::cout << "Creating ScavTrap" << std::endl;
	ScavTrap scav("Alice");
	std::cout << std::endl;

	std::cout << "Testing ClapTrap" << std::endl;
	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);
	std::cout << std::endl;

	std::cout << "Testing ScavTrap" << std::endl;
	scav.attack("enemy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	std::cout << std::endl;

	std::cout << "Destruction (reverse order)" << std::endl;
	return 0;
}