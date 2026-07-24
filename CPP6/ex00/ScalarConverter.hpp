/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 20:48:42 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/24 18:43:13 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();

	public:
		static void convert(const std::string& literal);
};
