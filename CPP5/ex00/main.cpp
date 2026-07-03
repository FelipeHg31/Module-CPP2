/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:06:02 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/03 00:39:48 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *one = new Bureaucrat("Juan", 100);
	Bureaucrat *error = new Bureaucrat("Error", -5);
	Bureaucrat *error2 = new Bureaucrat("Error", 200);

	std::cout << *one;
	std::cout << *error;
	std::cout << *error2;
	
	one->increment(30);
	std::cout << "Increment value: " << one->getRange() << std::endl;
	
	one->decrement(15);
	std::cout << "Decrement value: " << one->getRange() << std::endl;
	
	one->increment(150);
	one->decrement(150);
	
	std::cout << *one;

	delete one;
	delete error;
	delete error2;
}
