/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 18:28:29 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/14 18:32:23 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("Presidential", false, 25, 5), _target("No name"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):AForm("Presidential", false, 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void) other;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential form destroyed"<< std::endl;
}

bool PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	try
	{
		if (!getSign())
			throw AForm::NotSignedException();
		if (executor.getRange() > getCanExec())
			throw AForm::CantExecute();
		if (!execution())
			throw AForm::CantExecute();
		return (1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

bool PresidentialPardonForm::execution() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return (1);
}

