/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:48:32 by dibsejra          #+#    #+#             */
/*   Updated: 2025/11/25 21:29:53 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cctype>

int main()
{
	std::string sent = "HI THIS IS BRAIN";
	std::string *ptr = &sent;
	std::string &ref = sent;
	
	std::cout << &sent << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;

	std::cout << sent << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
}