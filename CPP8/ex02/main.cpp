/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:26:44 by juan-her          #+#    #+#             */
/*   Updated: 2026/08/14 17:05:15 by juan-her         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

static bool compare_forward(const MutantStack<int> &mstack, const std::list<int> &lst)
{
	MutantStack<int>::c_iterator mit = mstack.begin();
	std::list<int>::const_iterator lit = lst.begin();

	for (; mit != mstack.end() && lit != lst.end(); ++mit, ++lit)
	{
		if (*mit != *lit)
			return (false);
	}
	return (mit == mstack.end() && lit == lst.end());
}

static bool compare_reverse(const MutantStack<int> &mstack, const std::list<int> &lst)
{
	MutantStack<int>::cr_iterator mit = mstack.rbegin();
	std::list<int>::const_reverse_iterator lit = lst.rbegin();

	for (; mit != mstack.rend() && lit != lst.rend(); ++mit, ++lit)
	{
		if (*mit != *lit)
			return (false);
	}
	return (mit == mstack.rend() && lit == lst.rend());
}

int main()
{
	MutantStack<int> mstack;
	std::list<int> lst;

	mstack.push(5);
	lst.push_back(5);
	mstack.push(17);
	lst.push_back(17);
	std::cout << mstack.top() << std::endl;

	mstack.pop();
	lst.pop_back();
	std::cout << mstack.size() << " " << lst.size() << std::endl;

	mstack.push(3);
	lst.push_back(3);
	mstack.push(5);
	lst.push_back(5);
	mstack.push(737);
	lst.push_back(737);
	mstack.push(0);
	lst.push_back(0);
	
	std::cout << "forward:  " << (compare_forward(mstack, lst) ? "OK" : "KO") << std::endl;
	std::cout << "reverse:  " << (compare_reverse(mstack, lst) ? "OK" : "KO") << std::endl;
	return (0);
}
