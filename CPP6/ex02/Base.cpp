/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 02:14:47 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/23 04:04:07 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

#include <iostream>

Base::~Base() {}

Base *generate(void)
{
	int pos;

	std::srand(std::time(0));
	pos = std::rand() % 10;

	if (pos % 3 == 0)
		return (new A);
	else if (pos % 2 == 0)
		return (new B);
	else
		return (new C);
	return(NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "This is the class A" << std::endl;
		return ;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "This is the class B" << std::endl;
		return ;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "This is the class C" << std::endl;
		return ;
	}
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "This is the class A" << std::endl;
	}
	catch(...) {}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "This is the class B" << std::endl;
	}
	catch(...) {}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "This is the class C" << std::endl;
	}
	catch(...) {}
}
