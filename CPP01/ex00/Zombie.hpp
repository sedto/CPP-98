/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:18:28 by dibsejra          #+#    #+#             */
/*   Updated: 2025/11/25 21:30:17 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

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
	
	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif