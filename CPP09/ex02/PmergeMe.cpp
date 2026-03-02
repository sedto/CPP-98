/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:57:20 by dibsejra          #+#    #+#             */
/*   Updated: 2026/03/03 00:15:34 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

void PmergeMe::parse(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		std::string token(argv[i]);
		if (token.empty())
			throw std::runtime_error("Error: empty argument");

		for (size_t j = 0; j < token.size(); j++)
		{
			if (token[j] < '0' || token[j] > '9')
				throw std::runtime_error("Error: invalid argument '" + token + "': not a positive integer");
		}

		long val = std::atol(token.c_str());
		if (val <= 0 || val > 2147483647)
			throw std::runtime_error("Error: value out of range '" + token + "'");

		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}

	if (_vec.empty())
		throw std::runtime_error("Error: no valid integers provided");
}

// ---- Jacobsthal sequence ----
// J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
// Used to determine optimal insertion order
std::vector<int> PmergeMe::jacobsthalSequence(int n)
{
	std::vector<int> jac;
	jac.push_back(0);
	jac.push_back(1);
	while (jac.back() < n)
	{
		int size = static_cast<int>(jac.size());
		jac.push_back(jac[size - 1] + 2 * jac[size - 2]);
	}
	return jac;
}

// ---- VECTOR implementation ----

void PmergeMe::binaryInsertVec(std::vector<int>& arr, int val)
{
	int lo = 0;
	int hi = static_cast<int>(arr.size());

	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (arr[mid] < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	arr.insert(arr.begin() + lo, val);
}

void PmergeMe::mergeInsertVec(std::vector<int>& arr)
{
	int n = static_cast<int>(arr.size());
	if (n <= 1)
		return;

	// Step 1: Form pairs and sort each pair (larger first)
	std::vector<std::pair<int, int> > pairs;
	for (int i = 0; i + 1 < n; i += 2)
	{
		int a = arr[i];
		int b = arr[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b)); // (larger, smaller)
	}
	bool hasStraggler = (n % 2 == 1);
	int straggler = hasStraggler ? arr[n - 1] : 0;

	// Step 2: Recursively sort the larger elements
	std::vector<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);

	mergeInsertVec(largers);

	// Step 3: Build main chain = sorted largers
	// Find the paired smaller for each larger (after recursion, order changed)
	// We need to rebuild pairs mapping: for each larger in sorted order, find its smaller
	// largers is now sorted; we need to match them back to their pend (smaller)
	// Build pend array in same order as sorted largers
	// To do this, we sort pairs by their larger element
	std::vector<int> pend;
	{
		// Sort original pairs by larger element to match sorted largers
		std::vector<std::pair<int,int> > sortedPairs = pairs;
		std::sort(sortedPairs.begin(), sortedPairs.end());
		for (size_t i = 0; i < sortedPairs.size(); i++)
			pend.push_back(sortedPairs[i].second);
	}

	// Step 4: Insert pend elements using Jacobsthal order
	// b1 (pend[0]) is always <= a1 (largers[0]), insert first
	std::vector<int> mainChain = largers;
	mainChain.insert(mainChain.begin(), pend[0]);

	std::vector<int> jac = jacobsthalSequence(static_cast<int>(pend.size()));

	std::vector<bool> inserted(pend.size(), false);
	inserted[0] = true;

	// Insert in Jacobsthal order
	for (size_t k = 2; k < jac.size(); k++)
	{
		int jacIdx = jac[k] - 1; // 0-based
		if (jacIdx >= static_cast<int>(pend.size()))
			jacIdx = static_cast<int>(pend.size()) - 1;

		// Insert from jacIdx down to previous jacobsthal index
		int prevJac = jac[k - 1]; // 1-based, so prevJac-1 is 0-based
		for (int idx = jacIdx; idx >= prevJac; idx--)
		{
			if (idx < static_cast<int>(pend.size()) && !inserted[idx])
			{
				binaryInsertVec(mainChain, pend[idx]);
				inserted[idx] = true;
			}
		}
	}

	// Insert any remaining pend elements
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (!inserted[i])
			binaryInsertVec(mainChain, pend[i]);
	}

	// Insert straggler if present
	if (hasStraggler)
		binaryInsertVec(mainChain, straggler);

	arr = mainChain;
}

// ---- DEQUE implementation ----

void PmergeMe::binaryInsertDeq(std::deque<int>& arr, int val)
{
	int lo = 0;
	int hi = static_cast<int>(arr.size());

	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (arr[mid] < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	arr.insert(arr.begin() + lo, val);
}

void PmergeMe::mergeInsertDeq(std::deque<int>& arr)
{
	int n = static_cast<int>(arr.size());
	if (n <= 1)
		return;

	// Step 1: Form pairs and sort each pair (larger first)
	std::vector<std::pair<int, int> > pairs;
	for (int i = 0; i + 1 < n; i += 2)
	{
		int a = arr[i];
		int b = arr[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	bool hasStraggler = (n % 2 == 1);
	int straggler = hasStraggler ? arr[n - 1] : 0;

	// Step 2: Recursively sort the larger elements
	std::deque<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);

	mergeInsertDeq(largers);

	// Step 3: Build pend in order matching sorted largers
	std::vector<int> pend;
	{
		std::vector<std::pair<int,int> > sortedPairs = pairs;
		std::sort(sortedPairs.begin(), sortedPairs.end());
		for (size_t i = 0; i < sortedPairs.size(); i++)
			pend.push_back(sortedPairs[i].second);
	}

	// Step 4: Build main chain and insert pend in Jacobsthal order
	std::deque<int> mainChain(largers.begin(), largers.end());
	mainChain.insert(mainChain.begin(), pend[0]);

	std::vector<int> jac = jacobsthalSequence(static_cast<int>(pend.size()));

	std::vector<bool> inserted(pend.size(), false);
	inserted[0] = true;

	for (size_t k = 2; k < jac.size(); k++)
	{
		int jacIdx = jac[k] - 1;
		if (jacIdx >= static_cast<int>(pend.size()))
			jacIdx = static_cast<int>(pend.size()) - 1;

		int prevJac = jac[k - 1];
		for (int idx = jacIdx; idx >= prevJac; idx--)
		{
			if (idx < static_cast<int>(pend.size()) && !inserted[idx])
			{
				binaryInsertDeq(mainChain, pend[idx]);
				inserted[idx] = true;
			}
		}
	}

	for (size_t i = 0; i < pend.size(); i++)
	{
		if (!inserted[i])
			binaryInsertDeq(mainChain, pend[i]);
	}

	if (hasStraggler)
		binaryInsertDeq(mainChain, straggler);

	arr = mainChain;
}

// ---- sort() : times everything and prints ----

void PmergeMe::sort(void)
{
	// Print before
	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	// Sort with vector and time it
	std::clock_t startVec = std::clock();
	mergeInsertVec(_vec);
	std::clock_t endVec = std::clock();

	// Sort with deque and time it
	std::clock_t startDeq = std::clock();
	mergeInsertDeq(_deq);
	std::clock_t endDeq = std::clock();

	// Print after
	std::cout << "After:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
