/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:07:29 by dibsejra          #+#    #+#             */
/*   Updated: 2025/10/29 13:43:09 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cctype>

class HumanA
{
	private:
	std::string _name;
	Weapon &_weapon;

	public:
    HumanA(std::string name, Weapon &w); 
    ~HumanA(void);
    void attack() const;
};

#endif