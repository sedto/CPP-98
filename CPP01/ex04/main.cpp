/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:05:00 by dibsejra          #+#    #+#             */
/*   Updated: 2025/11/25 21:29:34 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& content, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t pos = 0;
	size_t found;

	if (s1.empty())
		return content;

	while (pos < content.length())
	{
		found = content.find(s1, pos);

		if (found == std::string::npos)
		{
			result.append(content, pos, content.length() - pos);
			break;
		}
		result.append(content, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}

	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
		return 1;
	}
	std::string content;
	std::string line;
	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += '\n';
	}
	infile.close();

	std::string result = replaceAll(content, s1, s2);
	std::string outFilename = filename + ".replace";
	std::ofstream outfile(outFilename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Could not create file '" << outFilename << "'" << std::endl;
		return 1;
	}

	outfile << result;
	outfile.close();

	std::cout << "File created successfully: " << outFilename << std::endl;

	return 0;
}
