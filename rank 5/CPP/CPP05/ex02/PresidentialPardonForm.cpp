/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:38:21 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/07 01:26:07 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
	AForm("Presidential Pardon", 25, 5)
{
	// std::cout<<"Presidential Pardon Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) :
	AForm("Presidential Pardon", 25, 5), _target(target)
{
	// std::cout<<"Presidential Pardon Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) :
	AForm(other), _target(other._target)
{
	// std::cout<<"Presidential Pardon Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	// std::cout<<"Presidential Pardon Copy assignment called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	// std::cout<<"Presidential Pardon Destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget( void ) const 
{
	return(_target);
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const 
{
	if (this->getIsSigned() != 1)
		throw(AForm::FormNotSignedException());
	if ( executor.getGrade() > this->getGradeToExec() )
		throw(AForm::GradeTooLowException());

	std::cout	<< this->getTarget()
				<< " has been pardoned by Zaphod Beeblebrox."
				<< std::endl;
}