/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:56:12 by dibsejra          #+#    #+#             */
/*   Updated: 2026/03/03 00:14:54 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <climits>

BitcoinExchange::BitcoinExchange(const std::string& dbFile)
{
	std::ifstream file(dbFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		std::string date = line.substr(0, comma);
		std::string rateStr = line.substr(comma + 1);

		float rate = static_cast<float>(std::atof(rateStr.c_str()));
		_db[date] = rate;
	}

	if (_db.empty())
		throw std::runtime_error("Error: database is empty.");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	// Format: YYYY-MM-DD
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}

	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	// Days per month
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// Leap year
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[2] = 29;

	if (day > daysInMonth[month])
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const
{
	if (valueStr.empty())
		return false;

	// Check for non-numeric characters (allow digits, dot, minus at start)
	size_t start = 0;
	if (valueStr[0] == '-' || valueStr[0] == '+')
		start = 1;

	bool hasDot = false;
	for (size_t i = start; i < valueStr.length(); i++)
	{
		if (valueStr[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (valueStr[i] < '0' || valueStr[i] > '9')
			return false;
	}

	if (start == valueStr.length())
		return false;

	// Convert to double first to detect overflow
	double dval = std::atof(valueStr.c_str());
	if (dval < 0.0)
	{
		value = static_cast<float>(dval);
		return true; // Let caller handle negative
	}
	if (dval > 1000.0)
	{
		value = static_cast<float>(dval);
		return true; // Let caller handle too large
	}

	value = static_cast<float>(dval);
	return true;
}

void BitcoinExchange::processInput(const std::string& inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header "date | value"

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		// Find " | " separator
		size_t sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 3);

		// Validate date
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		// Validate value
		float value = 0.0f;
		if (!isValidValue(valueStr, value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0.0f)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000.0f)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		// Find closest lower or equal date in DB
		std::map<std::string, float>::const_iterator it = _db.upper_bound(date);
		if (it == _db.begin())
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		--it;

		float rate = it->second;
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
}
