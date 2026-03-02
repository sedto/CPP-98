/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:56:48 by dibsejra          #+#    #+#             */
/*   Updated: 2026/03/03 00:15:22 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

RPN::RPN(void)
{
}

RPN::~RPN(void)
{
}

bool RPN::evaluate(const std::string& expression, int& result)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && (token[0] == '+' || token[0] == '-'
			|| token[0] == '*' || token[0] == '/'))
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error: not enough operands for operator '" << token << "'" << std::endl;
				return false;
			}

			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();

			if (token[0] == '+')
				_stack.push(a + b);
			else if (token[0] == '-')
				_stack.push(a - b);
			else if (token[0] == '*')
				_stack.push(a * b);
			else
			{
				if (b == 0)
				{
					std::cerr << "Error: division by zero" << std::endl;
					return false;
				}
				_stack.push(a / b);
			}
		}
		else if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
		{
			_stack.push(token[0] - '0');
		}
		else
		{
			std::cerr << "Error: invalid token '" << token << "'" << std::endl;
			return false;
		}
	}

	if (_stack.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return false;
	}

	result = _stack.top();
	return true;
}