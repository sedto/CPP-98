/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:35:00 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:35:01 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const & min(T const & a, T const & b)
{
	return (a < b) ? a : b;
}

template <typename T>
T const & max(T const & a, T const & b)
{
	return (a > b) ? a : b;
}

#endif
