/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 02:14:50 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/23 02:14:51 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <string>

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
#endif
