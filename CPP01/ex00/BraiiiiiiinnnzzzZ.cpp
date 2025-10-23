/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BraiiiiiiinnnzzzZ.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:18:28 by dibsejra          #+#    #+#             */
/*   Updated: 2025/10/23 15:29:45 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BraiiiiiiinnnzzzZ.hpp"


Zombie::Zombie(std::string name)
{
	this->_name = name;
}
Zombie::~Zombie(void)
{
	std::cout << this->_name << ": is destroyed" << std::endl;
}
void Zombie::annouce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

