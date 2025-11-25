/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:59:38 by dibsejra          #+#    #+#             */
/*   Updated: 2025/11/25 21:30:02 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 10;
	std::string name = "Julius";
	Zombie *horde = zombiehorde(N, name);
	for(int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
}