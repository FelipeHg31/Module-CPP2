/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:31:19 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/16 19:33:50 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **ag)
{
	if (ac != 2)
	{
		std::cout << "Only one value!" << std::endl;
		return (1);
	}
	ScalarConverter::convert(ag[1]);
	return (0);
}
