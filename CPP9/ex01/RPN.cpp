/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 21:38:02 by juan-her          #+#    #+#             */
/*   Updated: 2026/10/05 10:51:17 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stdlib.h>
#include <cctype>

RPN::RPN(){}

RPN::RPN(std::string line): _line(line){}

RPN::RPN(const RPN &other): _line(other._line)
{
	_stck = other._stck;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stck = other._stck;
		_line = other._line;
	}
	return (*this);
}

RPN::~RPN(){}

static bool is_RPNator(char c)
{
	if (c != '*' && c != '-' && c != '+' && c != '/')
		return (false);
	return (true);
}

float RPN::operation(float n1, float n2, char op)
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

float RPN::getResult()
{
	while (!_stck.empty())
		_stck.pop();
	for (size_t i = 0; i < _line.size(); i++)
	{
		if (_line[i] == ' ')
			continue;
		if (isdigit(static_cast<unsigned char>(_line[i])))
			_stck.push(_line[i] - '0');
		else if (is_RPNator(_line[i]))
		{
			float num1, num2;
			float res;
			
			if (_stck.size() < 2)
				throw(BadFormat());
			num1 = _stck.top();
			_stck.pop();
			num2 = _stck.top();
			_stck.pop();
			res = operation(num1, num2, _line[i]);
			_stck.push(res);
		}
		else
			throw(BadInput());
	}
	if (_stck.size() != 1)
		throw(BadInput());
	
	float res = _stck.top();
	_stck.pop();
	return (res);
}


