/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:56:25 by dibsejra          #+#    #+#             */
/*   Updated: 2026/03/03 00:15:02 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_db;

	BitcoinExchange(void);

	bool	isValidDate(const std::string& date) const;
	bool	isValidValue(const std::string& valueStr, float& value) const;

public:
	BitcoinExchange(const std::string& dbFile);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange(void);

	void	processInput(const std::string& inputFile) const;
};

#endif
