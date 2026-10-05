/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 02:16:16 by juan-her          #+#    #+#             */
/*   Updated: 2026/10/01 23:47:29 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <vector>
#include <string>
#include <exception>

class BadInput : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Only accepts positive integers");
		}
};
class BadFormat : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Integer out of range");
		}
};

template <typename T>
static size_t find_pos(const T& cont, int value)
{
	size_t i = 0;

	while (i < cont.size() && cont[i] != value)
		i++;
	return (i);
}

template <typename T>
static void binary_insert(T& cont, size_t end, int value)
{
	size_t left = 0;
	size_t right = end;
	size_t mid;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (value < cont[mid])
			right = mid;
		else
			left = mid + 1;
	}
	cont.insert(cont.begin() + left, value);
}

template <typename T>
void FordJohnson(T& cont)
{
	T big;
	T small;
	T chain;
	T pend;
	T a;
	size_t n = cont.size();
	bool odd = (n % 2 != 0);
	size_t m;
	size_t prev = 1;
	size_t jp = 1;
	size_t jn = 3;
	size_t top;
	size_t next;

	if (n <= 1)
		return;
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		if (cont[i] > cont[i + 1])
		{
			big.push_back(cont[i]);
			small.push_back(cont[i + 1]);
		}
		else
		{
			big.push_back(cont[i + 1]);
			small.push_back(cont[i]);
		}
	}
	chain = big;
	FordJohnson(chain);
	for (size_t k = 0; k < chain.size(); k++)
		pend.push_back(small[find_pos(big, chain[k])]);
	if (odd)
		pend.push_back(cont[n - 1]);
	a = chain;
	chain.insert(chain.begin(), pend[0]);
	m = pend.size();
	while (prev < m)
	{
		top = (jn < m) ? jn : m;
		for (size_t i = top; i > prev; i--)
		{
			if (odd && i == m)
				binary_insert(chain, chain.size(), pend[i - 1]);
			else
				binary_insert(chain, find_pos(chain, a[i - 1]), pend[i - 1]);
		}
		prev = jn;
		next = jn + 2 * jp;
		jp = jn;
		jn = next;
	}
	cont = chain;
}

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

	public:
		PmergeMe();
		PmergeMe(std::vector<int> vec, std::deque<int> deq);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		void show_cont();
		void compare();
};
