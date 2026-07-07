/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:28:27 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/10 19:28:27 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150) {
	// std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	// std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other )
{
	// std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
	// std::cout << "Bureaucrat Copy assignment called" << std::endl;
	if (this != &other)
	{
		const_cast<std::string&>(this->_name) = other.getName();
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat( void ) {
	// std::cout << "Bureaucrat Destructor called" << std::endl;
}

const std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade( void )
{
	if (this->_grade - 1 >= 1)
		--this->_grade;
	else
		throw (Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::decrementGrade( void )
{
	if (this->_grade + 1 <= 150)
		++this->_grade;
	else
		throw (Bureaucrat::GradeTooLowException());
}

const char* Bureaucrat::GradeTooHighException::what() const throw () {
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw () {
	return ("Grade too low!");
}

void	Bureaucrat::signForm( AForm &f )
{
	try
	{
		f.beSigned( *this );
		std::cout	<< this->getName() << " signed "
					<< f.getName() << "."
					<< std::endl; 
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cerr	<< this->getName() << " couldn’t sign "
					<< f.getName() << " because "
					<< e.what() << "." 
					<< std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout	<< this->_name
					<< " executed "
					<< form.getName()
					<< std::endl;
	}
	catch ( const std::exception &e )
	{
		std::cout	<< this->_name
					<< " couldnt execute "
					<< form.getName()
					<< " because: "
					<< e.what()
					<< std::endl;
	}
} 

std::ostream &operator<<(std::ostream &o, const Bureaucrat& bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (o);
}