/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 03:49:29 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/24 18:42:05 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base *b;

	std::srand(std::time(NULL));
	for (int i = 0; i < 5 ; i++)
	{
		b = generate();
		identify(b);
		identify(*b);
		delete(b);
	}
	
	
}
