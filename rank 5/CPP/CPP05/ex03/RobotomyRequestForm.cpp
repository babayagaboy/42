/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:37:42 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/07 02:08:06 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) :
	AForm("Robotomy Request", 72, 45)
{
	// std::cout<<"Robotomy Request Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) :
	AForm("Robotomy Request", 72, 45), _target(target)
{
	// std::cout<<"Robotomy Request Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) :
	AForm(other), _target(other._target)
{
	// std::cout<<"Robotomy Request Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	// std::cout<<"Robotomy Request Copy assignment called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	// std::cout<<"Robotomy Request Destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget( void ) const 
{
	return(_target);
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const 
{
	if (this->getIsSigned() != 1)
		throw(AForm::FormNotSignedException());
	if (executor.getGrade() > this->getGradeToExec())
		throw(AForm::GradeTooLowException());

	std::cout	<< "*drilling noises*"
				<< std::endl;
	
	if(rand() % 2)
	{
		std::cout	<< this->getTarget()
					<< " has been robotomized."
					<< std::endl;
	}
	else
	{
		std::cout	<< "Robotomy on "
					<< this->getTarget()
					<< " failed."
					<< std::endl;
	}
}