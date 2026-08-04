/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 20:49:25 by juan-her          #+#    #+#             */
/*   Updated: 2026/08/04 00:10:01 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>

void print(const T& x)
{
	std::cout << x << std::endl;
}

template <typename T>

void add(T& x)
{
	x++;
}

int main( void ) 
{
	int arr1[] = {1, 2, 3};
	const int arr2[] = {1, 2, 3};
	char arr3[] = {'c', 'b', 'a'};
	const char arr4[] = {'c', 'b', 'a'};
	
	::iter(arr1, 3, add<int>);
	::iter(arr1, 3, print<int>);
	//::iter(arr2, 3, add<int>);
	::iter(arr2, 3, print<int>);
	::iter(arr3, 3, add<char>);
	::iter(arr3, 3, print<char>);
	//::iter(arr4, 3, add<char>);
	::iter(arr4, 3, print<char>);

	return (0);
}
