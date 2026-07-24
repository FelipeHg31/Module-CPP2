/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:09:49 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/24 18:42:48 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <string>

typedef struct tData
{
	int num;
	std::string name;
	
}	Data;


class Serializer
{
	private:
		Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
