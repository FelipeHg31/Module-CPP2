/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:09:43 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/14 19:36:38 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
	(void) other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

AForm* Intern::createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target)); 
}

AForm* Intern::createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target)); 
}

AForm* Intern::createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target)); 
}

const char * Intern::NoExistName::what() const throw()
{
	return ("Error: form does not exist \n");
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	try
	{
		std::string forms[3] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};
	
		AForm* (*creators[3])(const std::string &) = {
			&createShrubbery,
			&createRobotomy,
			&createPresidential
		};
	
		for (int i=0; i < 3; i++)
		{
			if (name == forms[i])
			{
				std::cout << "Intern creates " << name << std::endl;
				return (creators[i](target));
			}
		}
		throw Intern::NoExistName();
	} catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}



