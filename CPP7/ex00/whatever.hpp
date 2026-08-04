/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:44:38 by juan-her          #+#    #+#             */
/*   Updated: 2026/08/02 20:16:38 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T &a, T&b)
{
	T c;
	
	c = a;
	a = b;
	b = c;
}

template <typename T>
T min(T a, T b)
{
	return (a > b ? b : a);
}

template <typename T>
T max(T a, T b)
{
	return (a > b ? a : b);
}
