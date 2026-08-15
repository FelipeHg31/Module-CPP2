/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 03:43:40 by juan-her          #+#    #+#             */
/*   Updated: 2026/08/06 04:42:53 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <vector>
#include <iterator>
#include <cstddef>
#include <algorithm>

class Span
{
	class ErrorFull : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	private:
		std::vector<int> _data;
		unsigned int _limit;
	public:
		Span();
		Span(unsigned int limit);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		
		template <typename Iter>
		void addRange(Iter b, Iter e)
		{
			size_t dist =  static_cast<size_t>(std::distance(b, e));
			
			if (_data.size() + dist > static_cast<size_t>(_limit))
				throw (ErrorFull());
			_data.insert(_data.end(), b, e);
		}
};
