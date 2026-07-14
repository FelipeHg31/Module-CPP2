/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:06:32 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/14 18:17:34 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shubbery", false, 145, 137), _target("No name") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
		AForm("Shubbery", false, 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery has been destroyed" << std::endl;
}

bool ShrubberyCreationForm::execute(const Bureaucrat & executor) const
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

bool ShrubberyCreationForm::execution() const
{
	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out.is_open())
		return (0);
	for(int i=0; i < 2; i++)
	{
		out << "  ^  " << std::endl;
		out << " ^^^ " << std::endl;
		out << "^^^^^" << std::endl;
		out << "  ^  " << std::endl;
		out << "  ^  \n" << std::endl;
	}
	return (1);
}
