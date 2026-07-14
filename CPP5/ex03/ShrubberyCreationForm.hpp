/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:19:50 by juan-her          #+#    #+#             */
/*   Updated: 2026/07/14 17:13:45 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHUBBERY_CREATION_FORM
#define SHUBBERY_CREATION_FORM

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		bool execute(const Bureaucrat& executor) const;
		bool execution() const;
};

#endif
