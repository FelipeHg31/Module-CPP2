/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 22:23:15 by juan-her          #+#    #+#             */
/*   Updated: 2026/10/05 09:47:17 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <exception>

class BitcoinExchange
{
	class ErrorBd : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class ErrorFile : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	private:
		std::string _file;
		std::map<std::string, double> _bd;

		void save_bd();
		void save_data(std::string& str);
		bool check_date(std::string& date);
		bool check_value(double num);
		void printLine(double res, int opc, std::vector<std::string> vec);
		void checkLine(std::string line);
	public:
		BitcoinExchange();
		BitcoinExchange(std::string file);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		void readFiles();
};
