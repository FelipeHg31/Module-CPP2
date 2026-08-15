/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 01:47:18 by juan-her          #+#    #+#             */
/*   Updated: 2026/08/06 02:47:43 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
	std::vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(14);
	vec.push_back(2);
	

	std::list<int> lis;
	lis.push_back(4);
	lis.push_back(5);
	lis.push_back(10);
	lis.push_back(40);
	
	std::deque<int> deq;
	deq.push_back(6);
	deq.push_back(31);
	deq.push_back(53);
	deq.push_back(7);
	
	try
	{
		{
			std::vector<int>::iterator it = ::easyfind<std::vector<int> >(vec, 3);
			if (*it == 3)
				std::cout << "Is correct first number" << std::endl;
			else
				std::cout << "Isn't correct first number" << std::endl;
			std::vector<int>::iterator it2 = ::easyfind<std::vector<int> >(vec, 355);
			(void) it2;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		{
			std::list<int>::iterator it = ::easyfind<std::list<int> >(lis, 10);
			if (*it == 10)
				std::cout << "Is correct middle number" << std::endl;
			else
				std::cout << "Isn't correct middle number" << std::endl;
			std::list<int>::iterator it2 = ::easyfind<std::list<int> >(lis, 'A');
			(void) it2;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		{
			std::deque<int>::iterator it = ::easyfind<std::deque<int> >(deq, 7);
			if (*it == 7)
				std::cout << "Is correct last number" << std::endl;
			else
				std::cout << "Isn't correct last number" << std::endl;
			std::deque<int>::iterator it2 = ::easyfind<std::deque<int> >(deq, 0);
			(void) it2;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
