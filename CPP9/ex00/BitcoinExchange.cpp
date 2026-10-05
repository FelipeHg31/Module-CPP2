/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 22:24:39 by juan-her          #+#    #+#             */
/*   Updated: 2026/10/01 22:24:42 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <cctype>

const char* BitcoinExchange::ErrorBd::what() const throw()
{
	return "Error in database";
}

const char* BitcoinExchange::ErrorFile::what() const throw()
{
	return "Error in the file";
}

BitcoinExchange::BitcoinExchange(): _file("")
{
}

BitcoinExchange::BitcoinExchange(std::string file): _file(file)
{
	save_bd();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _file(other._file), _bd(other._bd)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_file = other._file;
		_bd = other._bd;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

static void trim(std::string *str)
{
	size_t start = (*str).find_first_not_of(" \t");
	if (start == std::string::npos)
	{
		*str = "";
		return;
	}
	size_t end = (*str).find_last_not_of(" \t");
	*str = (*str).substr(start, end - start + 1);
}

static bool is_digits(const std::string &str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

// Solo acepta [+-]digitos[.digitos]: rechaza nan, inf, hex, 1e5...
static bool parse_num(const std::string &str, double *out)
{
	size_t i = 0;
	bool digit = false;
	bool dot = false;

	if (str.empty())
		return (false);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (i < str.size())
	{
		if (std::isdigit(static_cast<unsigned char>(str[i])))
			digit = true;
		else if (str[i] == '.' && !dot)
			dot = true;
		else
			return (false);
		i++;
	}
	if (!digit)
		return (false);
	*out = std::strtod(str.c_str(), NULL);
	return (true);
}

bool BitcoinExchange::check_date(std::string& date)
{
	static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	std::string ys;
	std::string ms;
	std::string ds;
	int y;
	int m;
	int d;
	int max;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	ys = date.substr(0, 4);
	ms = date.substr(5, 2);
	ds = date.substr(8, 2);
	if (!is_digits(ys) || !is_digits(ms) || !is_digits(ds))
		return (false);
	y = std::atoi(ys.c_str());
	m = std::atoi(ms.c_str());
	d = std::atoi(ds.c_str());
	if (m < 1 || m > 12 || d < 1)
		return (false);
	max = days[m - 1];
	if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
		max = 29;
	if (d > max)
		return (false);
	return (true);
}

bool BitcoinExchange::check_value(double num)
{
	if (num < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (num > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void BitcoinExchange::save_data(std::string& str)
{
	std::string date;
	double value;
	size_t pos;

	pos = str.find(',');
	if (pos == std::string::npos)
		throw(ErrorBd());
	date = str.substr(0, pos);
	if (!check_date(date))
	{
		std::cerr << "Error: in dates of the bd" << std::endl;
		throw(ErrorBd());
	}
	if (!parse_num(str.substr(pos + 1), &value) || value < 0)
	{
		std::cerr << "Error: in values of the bd" << std::endl;
		throw(ErrorBd());
	}
	_bd[date] = value;
}

void BitcoinExchange::save_bd()
{
	std::ifstream fd("data.csv");
	std::string str;

	if (!fd.is_open())
	{
		std::cerr << "Can't open the database file" << std::endl;
		throw(ErrorBd());
	}
	std::getline(fd, str);
	while (std::getline(fd, str))
	{
		if (str.empty())
			continue;
		save_data(str);
	}
	fd.close();
	if (_bd.empty())
		throw(ErrorBd());
}

void BitcoinExchange::checkLine(std::string line)
{
	std::vector<std::string> vec;
	std::map<std::string, double>::iterator it;
	double num;
	size_t pos;

	if (line.empty())
		return ;
	pos = line.find('|');
	if (pos == std::string::npos)
	{
		vec.push_back(line);
		printLine(0, 2, vec);
		return ;
	}
	vec.push_back(line.substr(0, pos));
	vec.push_back(line.substr(pos + 1));
	trim(&vec[0]);
	trim(&vec[1]);
	if (!check_date(vec[0]))
	{
		printLine(0, 2, vec);
		return ;
	}
	if (!parse_num(vec[1], &num))
	{
		printLine(0, 1, vec);
		return ;
	}
	if (!check_value(num))
		return ;
	it = _bd.lower_bound(vec[0]);
	if (it == _bd.end() || it->first != vec[0])
	{
		if (it == _bd.begin())
		{
			printLine(0, 2, vec);
			return ;
		}
		--it;
	}
	printLine(num * it->second, 0, vec);
}

void BitcoinExchange::printLine(double res, int opc, std::vector<std::string> vec)
{
	switch (opc)
	{
	case 0:
		std::cout << vec[0] + " => " + vec[1] + " = " << res << std::endl;
		break;
	case 1:
		std::cout << "Error: value not a number" << std::endl;
		break;
	case 2:
		std::cout << "Error: bad input => " + vec[0] << std::endl;
		break;
	}
}

void BitcoinExchange::readFiles()
{
	std::ifstream in(_file.c_str());
	std::string str;

	if (!in.is_open())
		throw(ErrorFile());
	std::getline(in, str);
	while (std::getline(in, str))
		checkLine(str);
	in.close();
}
