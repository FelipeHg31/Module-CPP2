/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 03:49:29 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/23 04:05:41 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main()
{
	Base *b;

	for (int i = 0; i < 5 ; i++)
	{
		b = generate();
		identify(b);
		identify(*b);
		delete(b);
	}
}
