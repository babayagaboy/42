/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 02:08:47 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/07 02:08:47 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void )
{
	// std::cout << "Intern Default constructor called." << std::endl;
}

Intern::Intern( const Intern& other )
{
	(void)other;
	// std::cout << "Intern Copy constructor called." << std::endl;
}

Intern& Intern::operator=( const Intern& other )
{
	// std::cout << "Intern Copy assignment called." << std::endl;
	if (this != &other) {}
	return (*this);
}

Intern::~Intern( void )
{
	// std::cout << "Intern Destructor called." << std::endl;
}

AForm*	Intern::makeForm( const std::string name, const std::string target)
{
	int i;
	std::string formNamesList[] = {
		"shrubbery creation", 
		"robotomy request", 
		"presidential pardon"};

	for (i = 0; i < 3; ++i)
	{
		if( formNamesList[i] == name )
		{
			std::cout	<< "Intern creates "
						<< name
						<< std::endl;
			break;
		}
	}
	switch (i)
	{
		case 0:
			return(new ShrubberyCreationForm(target));
		case 1:
			return(new RobotomyRequestForm(target));
		case 2:
			return(new PresidentialPardonForm(target));
		default:
			break;
	}
	return (NULL);
}