/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:20:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/24 20:17:46 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data *d = new Data;
	uintptr_t u;
	Data *a;

	d->name = "juan";
	d->num = 1;
	u = Serializer::serialize(d);
	a = Serializer::deserialize(u);
	if (a == d)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	delete d;
	return (0);
}
