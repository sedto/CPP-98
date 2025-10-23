/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BraiiiiiiinnnzzzZ.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:18:28 by dibsejra          #+#    #+#             */
/*   Updated: 2025/10/23 15:38:45 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIIIIIIINNNZZZZ_HPP
#define BRAIIIIIIINNNZZZZ_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cctype>

class Zombie
{
	private:
	std::string _name;

	public:
	Zombie(std::string name);
	
	~Zombie(void);
	
	void annouce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif