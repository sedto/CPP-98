/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:56:32 by dibsejra          #+#    #+#             */
/*   Updated: 2026/03/03 00:15:09 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments." << std::endl;
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc("data.csv");
		btc.processInput(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}