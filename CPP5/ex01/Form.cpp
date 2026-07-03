/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 05:30:49 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/03 19:01:44 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

Form::Form(): _name("none"), _sign(false), _canSign(0), _canExec(0){}

Form::Form(const std::string name, bool sign, int canSign, int canExec):
	_name(name), _sign(sign), _canSign(canSign), _canExec(canExec)
{
	if (canSign > 150 || canExec > 150)
		throw GradeTooLowException();
	if (canSign < 1 || canExec < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& other): _name(other._name), _sign(other._sign), _canSign(other._canSign), _canExec(other._canExec)
{
	if (other._canSign > 150 || other._canExec > 150)
		throw GradeTooLowException();
	if (other._canSign < 1 || other._canExec < 1)
		throw GradeTooHighException();
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_sign = other._sign;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

std::string const & Form::getName() const
{
	return (_name);
}

int Form::getCanSign() const
{
	return (_canSign);
}

int Form::getCanExec() const
{
	return (_canExec);
}

bool Form::getSign() const
{
	return (_sign);
}

bool Form::beSigned(Bureaucrat& b)
{
	try
	{
		if (!_sign)
		{
			if (_canSign >= b.getRange())
			{
				_sign = true;
				return (true);
			}
			else
				throw GradeTooLowException();
		}
		else
			std::cout << "The form is alredy sign" << std::endl;
	}
	catch (Form::GradeTooLowException&)
	{
		std::cout << "The range is lower, cant sign form." << std::endl;
	}
	return (false);
}

std::ostream& operator <<(std::ostream& out, const Form& obj)
{
	std::string is;
	if (obj.getSign())
		is = "signed";
	else
		is = "not signed";
	out << "Form:\n" << obj.getName() << ", is " << is << ", range to signed: " 
			<< obj.getCanSign() << ", range to executed: " << obj.getCanExec() << std::endl;
	return (out);
}



