/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:06:01 by juan-her          #+#    #+#             */
/*   Updated: 2026/08/14 17:25:27 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator	iterator;
		typedef typename Container::const_iterator	c_iterator;
		typedef typename Container::reverse_iterator r_iterator;
		typedef typename Container::const_reverse_iterator cr_iterator;
		
		MutantStack(): std::stack<T, Container>(){}
		MutantStack(const MutantStack &other): std::stack<T, Container>(other){}
		MutantStack& operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T, Container>::operator=(other);
			return (*this);
		}

		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}

		c_iterator begin() const 
		{
			return this->c.begin();
		}
		c_iterator end() const
		{
			return this->c.end();
		}

		r_iterator rbegin()
		{
			return this->c.rbegin();
		}
		r_iterator rend()
		{
			return this->c.rend();
		}

		cr_iterator rbegin() const
		{
			return this->c.rbegin();
		}
		cr_iterator rend() const
		{
			return this->c.rend();
		}
};
