/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:56:10 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/14 19:42:21 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	std::cout << "\n========== INTERN: makeForm tests ==========\n" << std::endl;

	Intern *someone = new Intern();
	Intern *copy = new Intern(*someone);

	AForm *shrub = someone->makeForm("shrubbery creation", "garden");
	AForm *robo  = someone->makeForm("robotomy request", "Bender");
	AForm *pres  = someone->makeForm("presidential pardon", "Zaphod");
	AForm *bad   = copy->makeForm("nonexistent", "nowhere");

	std::cout << "\n--- Checking pointers (shrub/robo/pres should be non-NULL, bad should be NULL) ---" << std::endl;
	std::cout << "shrub: " << (shrub ? "OK" : "NULL") << std::endl;
	std::cout << "robo:  " << (robo ? "OK" : "NULL") << std::endl;
	std::cout << "pres:  " << (pres ? "OK" : "NULL") << std::endl;
	std::cout << "bad:   " << (bad ? "OK" : "NULL") << std::endl;

	std::cout << "\n========== INTERN: copy destroyed ==========" << std::endl;
	delete copy;

	std::cout << "\n========== BUREAUCRAT creation ==========\n" << std::endl;

	Bureaucrat *high = new Bureaucrat("HighRank", 1);
	Bureaucrat *mid  = new Bureaucrat("MidRank", 50);
	Bureaucrat *low  = new Bureaucrat("LowRank", 150);

	std::cout << "\n========== SIGN tests ==========\n" << std::endl;

	std::cout << "--- LowRank tries to sign Shrubbery (needs 145) ---" << std::endl;
	low->signForm(*shrub);
	std::cout << "   shrub signed? " << (shrub->getSign() ? "yes" : "no") << std::endl;

	std::cout << "\n--- MidRank signs Shrubbery (grade 50 <= 145) ---" << std::endl;
	mid->signForm(*shrub);
	std::cout << "   shrub signed? " << (shrub->getSign() ? "yes" : "no") << std::endl;

	std::cout << "\n--- MidRank signs Robotomy (needs 72) ---" << std::endl;
	mid->signForm(*robo);
	std::cout << "   robo signed? " << (robo->getSign() ? "yes" : "no") << std::endl;

	std::cout << "\n--- MidRank signs Presidential (needs 25) ---" << std::endl;
	mid->signForm(*pres);
	std::cout << "   pres signed? " << (pres->getSign() ? "yes" : "no") << std::endl;

	std::cout << "\n--- HighRank signs Presidential ---" << std::endl;
	high->signForm(*pres);
	std::cout << "   pres signed? " << (pres->getSign() ? "yes" : "no") << std::endl;

	std::cout << "\n========== EXECUTE tests ==========\n" << std::endl;

	std::cout << "--- LowRank tries to execute Shrubbery (needs 137) ---" << std::endl;
	high->executeForm(*shrub);
	low->executeForm(*shrub);
	high->executeForm(*shrub);

	std::cout << "\n--- Execute Robotomy (needs grade 45) ---" << std::endl;
	mid->executeForm(*robo);
	high->executeForm(*robo);

	std::cout << "\n--- Execute Presidential (needs grade 5) ---" << std::endl;
	high->executeForm(*pres);
	mid->executeForm(*pres);
	high->executeForm(*pres);

	std::cout << "\n========== BUREAUCRAT increment/decrement ==========\n" << std::endl;
	std::cout << *high;
	high->increment(1);
	std::cout << *high;
	high->decrement(1);
	std::cout << *high;
	high->decrement(200);

	std::cout << "\n========== CLEANUP ==========\n" << std::endl;
	delete high;
	delete mid;
	delete low;
	delete shrub;
	delete robo;
	delete pres;
	delete someone;
	return (0);
}
