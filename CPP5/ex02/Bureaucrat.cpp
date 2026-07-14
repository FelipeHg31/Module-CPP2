/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:43:25 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/14 19:38:32 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

Bureaucrat::Bureaucrat(): _name("none"), _range(0){}

Bureaucrat::Bureaucrat(const std::string name, int range): _name(name)
{
	try{
		if (range < 1 || range > 150)
		{
			if (range < 1)
				throw GradeTooHighException();
			else
				throw GradeTooLowException();
			_range = 0;
		}
		else
			_range = range;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _range(other._range){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_range = other._range;
	}
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat " << _name << " destroyed"<<std::endl;
}

std::string const &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getRange() const
{
	return (_range);
}

void Bureaucrat::increment(int n)
{ 
	try{
		if ((_range - n) < 1)
			throw GradeTooHighException();
		else
			_range -= n;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decrement(int n)
{
	n -= 1;
	try{
		if ((_range + n) > 150)
			throw GradeTooLowException();
		else
			_range += n;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	int num;

	num = obj.getRange();
	out << obj.getName() << ", burecraft grade " << num << std::endl;
	return (out);
}

void Bureaucrat::signForm(AForm& f)
{
	if (f.beSigned(*this))
		std::cout << *this << "signed " << f << std::endl;
	else
		std::cout << *this << " couldn’t sign " << f << std::endl;
}

void Bureaucrat::executeForm(const AForm& form)
{
	if (form.execute(*this))
		std::cout << _name + " executed " + form.getName() << std::endl;
	else
		std::cout << _name + " couldn't execute " + form.getName() << std::endl;
}


