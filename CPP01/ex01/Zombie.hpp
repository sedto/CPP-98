/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:58:20 by dibsejra          #+#    #+#             */
/*   Updated: 2025/11/25 21:29:59 by dibsejra         ###   ########.fr       */
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
	Zombie();
	Zombie(std::string name);
	
	~Zombie(void);
	
	void announce(void);
	void setName(std::string name);

};
	Zombie* zombiehorde(int N, std::string name);

#endif