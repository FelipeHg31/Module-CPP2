/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 18:56:32 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/14 19:30:08 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>
class AForm;

class Intern
{
	private:
		static AForm* createShrubbery(const std::string& target);
		static AForm* createRobotomy(const std::string& target);
		static AForm* createPresidential(const std::string& target);
	public:

		class NoExistName : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern& other);
		~Intern();
		AForm* makeForm(const std::string& name, const std::string& target);
};

#endif
