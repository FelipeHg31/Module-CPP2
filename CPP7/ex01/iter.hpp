/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 20:53:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/08/04 00:09:38 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

template <typename A, typename F>

void iter(const A *array, const size_t num, F func)
{
	for (size_t i = 0; i < num; i++)
		func(array[i]);
}

template <typename A, typename F>

void iter(A *array, const size_t num, F func)
{
	for (size_t i = 0; i < num; i++)
		func(array[i]);
}
