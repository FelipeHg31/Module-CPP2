/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 01:47:52 by juan-her          #+#    #+#             */
/*   Updated: 2026/08/06 02:17:36 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

class Not_found : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("The number is not found");
		}
};

template <typename T>
typename T::iterator easyfind(T &cont, int value)
{
	typename T::iterator iter;
	
	iter = std::find(cont.begin(), cont.end(), value);
	if (iter == cont.end())
		throw Not_found();
	return (iter);
}
