/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:45:25 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/14 18:23:00 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm():AForm("Robotomy", false, 72, 45), _target("No name"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):AForm("Robotomy", false, 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void) other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destroyed"<< std::endl;
}

bool RobotomyRequestForm::execute(const Bureaucrat& executor) const
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

bool RobotomyRequestForm::execution() const
{
	std::cout << "Make some some drilling noises" << std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully" << std::endl;
		return (1);
	}
	else
	{
		std::cout << "Robotomy failed on " << _target << std::endl;
		return (0);
	}
}
