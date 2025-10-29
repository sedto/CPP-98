/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:07:29 by dibsejra          #+#    #+#             */
/*   Updated: 2025/10/29 13:28:23 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cctype>

class Weapon
{
	private:
	std::string _type;

	public:
	Weapon(std::string type);
	~Weapon(void);
	
	const std::string& getType() const;
	void setType(std::string new_type);

};

#endif