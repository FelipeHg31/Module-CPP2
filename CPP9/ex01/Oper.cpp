/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Oper.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 21:38:02 by juan-her          #+#    #+#             */
/*   Updated: 2026/10/05 09:40:57 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Oper.hpp"
#include <iostream>
#include <stdlib.h>
#include <cctype>

Oper::Oper(){}

Oper::Oper(std::string line): _line(line){}

Oper::Oper(const Oper &other): _line(other._line)
{
	std::vector<float>::const_iterator it ;
	it = other._stck.begin();
	for (; it != other._stck.end(); ++it)
		_stck.push_back(*it);
}

Oper& Oper::operator=(const Oper& other)
{
	if (this != &other)
	{
		if (_stck.size() > 0)
			_stck.clear();
		std::vector<float>::const_iterator it ;
		it = other._stck.begin();
		for (; it != other._stck.end(); ++it)
			_stck.push_back(*it);
	}
	return (*this);
}

Oper::~Oper(){}

static bool is_operator(char c)
{
	if (c != '*' && c != '-' && c != '+' && c != '/')
		return (false);
	return (true);
}

float Oper::operation(float n1, float n2, char op)
{
	switch (op)
	{
		case '+':
			return (n2 + n1);
		break;
		case '-':
			return(n2 - n1);
		break;
		case '*':
			return(n2 * n1);
		break;
		case '/':
			if (n1 == 0)
				throw(BadFormat());
			return(n2 / n1);
		break;
	}
	return (0);
}

float Oper::getResult()
{
	for (size_t i = 0; i < _line.size(); i++)
	{
		if (_line[i] == ' ')
			continue;
		if (isdigit(_line[i]))
			_stck.push_back(_line[i] - '0');
		else if (is_operator(_line[i]))
		{
			float num1, num2;
			float res;
			
			if (_stck.size() < 2)
				throw(BadFormat());
			num1 = _stck.back();
			_stck.pop_back();
			num2 = _stck.back();
			_stck.pop_back();
			res = operation(num1, num2, _line[i]);
			_stck.push_back(res);
		}
		else
			throw(BadInput());
	}
	if (_stck.size() > 1)
		throw(BadInput());
	return (_stck.back());
}


