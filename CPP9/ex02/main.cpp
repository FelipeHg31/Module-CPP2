/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 23:48:43 by juan-her          #+#    #+#             */
/*   Updated: 2026/10/05 12:00:58 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <climits>
#include "PmergeMe.hpp"

static int Parse_Number(const std::string& num)
{
	long n;

	if (num.find_first_not_of("0123456789") != std::string::npos)
		throw(BadInput());
	if (num.size() > 10)
		throw(BadFormat());
	n = std::strtol(num.c_str(), NULL, 10);
	if (n > INT_MAX || n < 0)
		throw(BadFormat());
	return (static_cast<int>(n));
}

static void insert_Number(const std::string& line, std::vector<int>& vec, std::deque<int>& deq)
{
	std::stringstream ss(line);
	std::string token;
	int num;

	while (ss >> token)
	{
		num = Parse_Number(token);
		vec.push_back(num);
		deq.push_back(num);
	}
}

static bool no_repeat(const std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (vec[j] == vec[i])
				return (false);
		}
	}
	return (true);
}

int main(int ac, char **ag)
{
	std::vector<int> vec;
	std::deque<int> deq;

	if (ac < 2)
	{
		std::cerr << "Error: no input" << std::endl;
		return (1);
	}
	if (!ag[1][0])
		return(1);
	try
	{
		for (int i = 1; i < ac; i++)
			insert_Number(ag[i], vec, deq);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	if (vec.empty() || !no_repeat(vec))
	{
		std::cerr << "Error: invalid or repeated input" << std::endl;
		return (1);
	}
	PmergeMe merge(vec, deq);
	merge.compare();
	return (0);
}
