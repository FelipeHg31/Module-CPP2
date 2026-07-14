/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:56:10 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/14 18:35:36 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat *felipe = new Bureaucrat("Felipe", 5);
	Bureaucrat *juan = new Bureaucrat("Juan", 150);
	ShrubberyCreationForm *form1 = new ShrubberyCreationForm("Primera");
	RobotomyRequestForm *form2 = new RobotomyRequestForm("segundo");
	PresidentialPardonForm *form3 = new PresidentialPardonForm("tercero");
	
	juan->signForm(*form1);
	felipe->signForm(*form1);
	felipe->executeForm(*form1);
	std::cout << std::endl;
	juan->signForm(*form2);
	felipe->signForm(*form2);
	felipe->executeForm(*form2);
	std::cout << std::endl;
	juan->signForm(*form3);
	felipe->signForm(*form3);
	felipe->executeForm(*form3);
	std::cout << std::endl;
	delete(felipe);
	delete(juan);
	delete (form1);
	delete (form2);
	delete (form3);
	
}
