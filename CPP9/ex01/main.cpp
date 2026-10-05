/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 21:19:01 by juan-her          #+#    #+#             */
/*   Updated: 2026/10/05 10:46:06 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int ac, char **ag)
{
	if (ac != 2 || !ag[1] || !ag[1][0])
	{
		std::cerr << "No arguments" << std::endl;
		return (1);
	}
	RPN oper(ag[1]);
	float result;

	try
	{
		result = oper.getResult();
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
