/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:45:12 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/14 19:38:48 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("The form is not signed");
}

const char* AForm::CantExecute::what() const throw()
{
	return ("The form cant be execute");
}

AForm::AForm(): _name("none"), _sign(false), _canSign(150), _canExec(150){}

AForm::AForm(const std::string name, bool sign, int canSign, int canExec):
	_name(name), _sign(sign), _canSign(canSign), _canExec(canExec)
{
	if (canSign > 150 || canExec > 150)
		throw GradeTooLowException();
	if (canSign < 1 || canExec < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other): _name(other._name), _sign(other._sign), _canSign(other._canSign), _canExec(other._canExec)
{
	if (other._canSign > 150 || other._canExec > 150)
		throw GradeTooLowException();
	if (other._canSign < 1 || other._canExec < 1)
		throw GradeTooHighException();
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_sign = other._sign;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << " destroyed" << std::endl;
}

std::string const & AForm::getName() const
{
	return (_name);
}

int AForm::getCanSign() const
{
	return (_canSign);
}

int AForm::getCanExec() const
{
	return (_canExec);
}

bool AForm::getSign() const
{
	return (_sign);
}

bool AForm::beSigned(const Bureaucrat& b)
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
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (false);
}

std::ostream& operator <<(std::ostream& out, const AForm& obj)
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



