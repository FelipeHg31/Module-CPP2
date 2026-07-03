/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:21:58 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/03 19:29:49 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *can = new Bureaucrat("Felipe", 1);
	Bureaucrat *notcan = new Bureaucrat("Juan", 150);
	Form *one = new Form("First", false, 5, 5);
	Form *two = new Form("two", false, 5, 5);
	Form *alredy = new Form("Alredy", true, 6, 140);
	//Form *lowerS = new Form("lowerS", false, 0, 1);
	//Form *higherS = new Form("HighS", false, 155, 1);
	//Form *lowerE = new Form("LowerE", false, 10, 0);
	//Form *higherE = new Form("HighE", false, 15, 152);

	std::cout << *can << std::endl;
	std::cout << one->beSigned(*can) << std::endl;
	can->signForm(*one);
	notcan->signForm(*two);
	can->signForm(*two);
	notcan->signForm(*alredy);

	delete can;
	delete notcan;
	delete one;
	delete two;
	delete alredy;
}
