/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:12:58 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/16 21:26:51 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t ser;
	
	if (!ptr)
		return (0);
	ser = reinterpret_cast<uintptr_t>(ptr);
	if (!ser)
		return (0);
	return (ser);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *deser;

	if (!raw)
		return (NULL);
	deser = reinterpret_cast<Data *>(raw);
	if (!deser)
		return (NULL);
	return (deser);
}
