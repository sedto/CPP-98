/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:09:01 by dibsejra          #+#    #+#             */
/*   Updated: 2025/10/29 15:12:58 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return(1);
	}
	for (int i = 1; i < argc ; i++)
	{
		std::string str = argv[i];
		for(size_t j = 0; j < str.length(); j++)
		{
			str[j] = std::toupper(str[j]);
		}
		std::cout << str;
	}
	std::cout << '\n';
	return 0;
}