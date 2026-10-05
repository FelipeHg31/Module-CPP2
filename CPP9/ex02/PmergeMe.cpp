/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 02:39:23 by juan-her          #+#    #+#             */
/*   Updated: 2026/09/12 06:03:20 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(std::vector<int> vec, std::deque<int> deq): _vec(vec), _deq(deq)
{
}

PmergeMe::PmergeMe(const PmergeMe& other): _vec(other._vec), _deq(other._deq)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::show_cont()
{
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
}

void PmergeMe::compare()
{
	std::cout << "Before:";
	show_cont();
	std::cout << std::endl;

	clock_t start_v = clock();
	FordJohnson<std::vector<int> >(_vec);
	clock_t end_v = clock();

	clock_t start_dq = clock();
	FordJohnson<std::deque<int> >(_deq);
	clock_t end_dq = clock();

	std::cout << "After:";
	show_cont();
	std::cout << std::endl;

	double time_vec = (double)(end_v - start_v) * 1e6 / CLOCKS_PER_SEC;
	double time_dq = (double)(end_dq - start_dq) * 1e6 / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector<int> : ";
	std::cout << std::fixed << std::setprecision(6) << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque<int> : ";
	std::cout << std::fixed << std::setprecision(6) << time_dq << " us" << std::endl;
}
