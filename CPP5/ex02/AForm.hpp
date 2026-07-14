/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:45:21 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/14 14:11:02 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _sign;
		int const _canSign;
		int const _canExec;
	public:
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
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class CantExecute : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		AForm();
		AForm(const std::string name, bool sign, int canSign, int canExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		std::string const &getName() const;
		int getCanSign() const;
		int	 getCanExec() const;
		bool getSign() const;
		bool beSigned(const Bureaucrat& b);
		virtual bool execute(const Bureaucrat& b) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);
#endif
