/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:57:15 by dibsejra          #+#    #+#             */
/*   Updated: 2026/03/03 00:15:30 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: no arguments provided." << std::endl;
		std::cerr << "Usage: ./PmergeMe <positive integers>" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pm;
		pm.parse(argc, argv);
		pm.sort();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
