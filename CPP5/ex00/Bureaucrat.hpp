/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:05:58 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/03 00:10:16 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>


class Bureaucrat
{
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	private:
		std::string const _name;
		int _range;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int range);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::string const &getName() const;
		int getRange() const;
		void increment(int n);
		void decrement(int n);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif
