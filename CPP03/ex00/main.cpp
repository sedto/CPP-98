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

int main(void)
{
	ClapTrap clap1("Bob");
	ClapTrap clap2("Alice");

	clap1.attack("Alice");
	clap2.takeDamage(0);
	clap2.beRepaired(5);

	clap1.attack("Alice");
	clap1.attack("Alice");
	clap1.attack("Alice");
	clap1.attack("Alice");
	clap1.attack("Alice");
	clap1.attack("Alice");
	clap1.attack("Alice");
	clap1.attack("Alice");
	clap1.attack("Alice");
	clap1.attack("Alice");

	clap2.takeDamage(8);
	clap2.takeDamage(5);

	return 0;
}