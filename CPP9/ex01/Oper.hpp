/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Oper.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 19:56:31 by juan-her          #+#    #+#             */
/*   Updated: 2026/10/01 23:57:48 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <vector>
#include <string>

class Oper
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
		std::vector<float> _stck;
		std::string _line;
	public:
		Oper();
		Oper(std::string line);
		Oper(const Oper &other);
		Oper& operator=(const Oper& other);
		~Oper();
		float getResult();
		float operation(float n1, float n2, char op);

};

