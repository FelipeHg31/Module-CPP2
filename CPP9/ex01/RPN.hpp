/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 19:56:31 by juan-her          #+#    #+#             */
/*   Updated: 2026/10/05 10:43:19 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <stack>
#include <string>

class RPN
{
	class BadInput : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("ERROR");
			}
	};
	class Limit : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("The result have overflow");
			}
	};
	class BadFormat : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("The format of the operation is wrong");
			}
	};
	
	private:
		std::stack<float> _stck;
		std::string _line;
	public:
		RPN();
		RPN(std::string line);
		RPN(const RPN &other);
		RPN& operator=(const RPN& other);
		~RPN();
		float getResult();
		float operation(float n1, float n2, char op);

};

