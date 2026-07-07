/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:34:48 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/07 02:04:41 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	AForm("Shrubbery Creation", 145, 137)
{
	// std::cout<<"Shrubbery Creation Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) :
	AForm("Shrubbery Creation", 145, 137), _target(target)
{
	// std::cout<<"Shrubbery Creation Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) :
	AForm(other), _target(other._target)
{
	// std::cout<<"Shrubbery Creation Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	// std::cout<<"Shrubbery Creation Copy assignment called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	// std::cout<<"Shrubbery Creation Destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget( void ) const 
{
	return(_target);
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (this->getIsSigned() != 1)
		throw(AForm::FormNotSignedException());
	if (executor.getGrade() > this->getGradeToExec())
		throw(AForm::GradeTooLowException());

	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
	if (file.is_open()) 
	{
		file << "           &&& &&  & &&                        &&& &&  & &&                        &&& &&  & &&\n"
         << "       && &\\/&\\|& ()|/ @, &&               && &\\/&\\|& ()|/ @, &&               && &\\/&\\|& ()|/ @, &&\n"
         << "       &\\/(/&/&||/& /_/)_&/_&              &\\/(/&/&||/& /_/)_&/_&              &\\/(/&/&||/& /_/)_&/_&\n"
         << "    &() &\\/&|()|/&\\/ '%\" & ()           &() &\\/&|()|/&\\/ '%\" & ()           &() &\\/&|()|/&\\/ '%\" & ()\n"
         << "   &_\\_&&_\\ |& |&&/&__%_/_& &&         &_\\_&&_\\ |& |&&/&__%_/_& &&         &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
         << "   &&   && & &| &| /& & % ()& /&&      &&   && & &| &| /& & % ()& /&&      &&   && & &| &| /& & % ()& /&&\n"
         << "    ()&_---()&\\&\\|&&-&&--%---()~        ()&_---()&\\&\\|&&-&&--%---()~        ()&_---()&\\&\\|&&-&&--%---()~\n"
         << "          &&     |||                          &&     |||                          &&     |||\n"
         << "                 |||                                 |||                                 |||\n"
         << "                 |||                                 |||                                 |||\n"
         << "                 |||                                 |||                                 |||\n"
         << "           , -=-~  .-^- _                      , -=-~  .-^- _                      , -=-~  .-^- _\n";
    	file.close();
	}
}