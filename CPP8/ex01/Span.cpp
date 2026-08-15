/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 04:10:35 by juan-her          #+#    #+#             */
/*   Updated: 2026/08/06 04:50:15 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char* Span::ErrorFull::what() const throw()
{
	return ("The container dont have space");
}

Span::Span(): _data(std::vector<int>()), _limit(0) {}

Span::Span(unsigned int limit): _data(std::vector<int>()), _limit(limit){}

Span::Span(const Span &other): _limit(other._limit)
{
	for (size_t i = 0; i < other._data.size(); i++)
		_data.push_back(other._data[i]);
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_limit = other._limit;
		_data.clear();
		for (size_t i = 0; i < other._data.size(); i++)
			_data.push_back(other._data[i]);
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (_data.size() == static_cast<size_t>(_limit))
		throw (ErrorFull());
	_data.push_back(num);
}

int Span::shortestSpan()
{
	if (_data.size() < 2)
		throw (ErrorFull());
	
	std::sort(_data.begin(), _data.end());
	int min = _data[1] - _data[0];
	for (size_t i = 1; i + 1 < _data.size(); i++)
	{
		int diff = _data[i + 1] - _data[i];
		if (min > diff)
			min = diff;
	}
	return (min);
}

int Span::longestSpan()
{
	if (_data.size() < 2)
		throw (ErrorFull());
	
	std::sort(_data.begin(), _data.end());
	return (_data.back() - _data.front());
}
