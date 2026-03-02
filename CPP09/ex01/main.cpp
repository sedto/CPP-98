/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:56:59 by dibsejra          #+#    #+#             */
/*   Updated: 2026/03/03 00:15:18 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments." << std::endl;
		std::cerr << "Usage: ./RPN \"<expression>\"" << std::endl;
		return 1;
	}

	RPN rpn;
	int result = 0;

	if (!rpn.evaluate(argv[1], result))
		return 1;

	std::cout << result << std::endl;
	return 0;
}