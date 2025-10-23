/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:18:28 by dibsejra          #+#    #+#             */
/*   Updated: 2025/10/23 15:37:20 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BraiiiiiiinnnzzzZ.hpp"

void randomChump( std::string name )
{
	Zombie z(name);
	z.annouce();
}
Zombie* newZombie( std::string name)
{
	Zombie* z1 = new Zombie(name);
	return(z1);
}
int main ()
{
	randomChump("Sami le salami");
	Zombie *z1 = newZombie("Cbibi");
	z1->annouce();
	delete z1;
	return(0);
}