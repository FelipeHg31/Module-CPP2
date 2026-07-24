/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 02:14:50 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/24 20:36:59 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

