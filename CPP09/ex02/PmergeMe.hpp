/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:57:24 by dibsejra          #+#    #+#             */
/*   Updated: 2026/03/03 00:15:39 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;

	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

	// Ford-Johnson for vector
	void	mergeInsertVec(std::vector<int>& arr);
	void	binaryInsertVec(std::vector<int>& arr, int val);

	// Ford-Johnson for deque
	void	mergeInsertDeq(std::deque<int>& arr);
	void	binaryInsertDeq(std::deque<int>& arr, int val);

	// Jacobsthal sequence helper
	static std::vector<int>	jacobsthalSequence(int n);

public:
	PmergeMe(void);
	~PmergeMe(void);

	void	parse(int argc, char* argv[]);
	void	sort(void);
};

#endif
