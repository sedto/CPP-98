/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:00:00 by dibsejra          #+#    #+#             */
/*   Updated: 2026/03/03 00:15:25 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN
{
private:
	std::stack<int>	_stack;

	RPN(const RPN& other);
	RPN& operator=(const RPN& other);

public:
	RPN(void);
	~RPN(void);

	bool	evaluate(const std::string& expression, int& result);
};

#endif
