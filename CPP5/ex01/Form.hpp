#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	private:
		std::string const _name;
		bool _sign;
		int const _canSign;
		int const _canExec;
	public:
		Form();
		Form(const std::string name, bool sign, int canSign, int canExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		std::string const &getName() const;
		int getCanSign() const;
		int	 getCanExec() const;
		bool getSign() const;
		bool beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, const Form& obj);
#endif
