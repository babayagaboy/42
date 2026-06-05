/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:09:57 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 18:12:13 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("Default") {
	// std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria( const std::string& type ) : _type(type) {
	// std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria( const AMateria& other )
{
	// std::cout << "AMateria Copy constructor called" << std::endl;
	*this = other;
}

AMateria& AMateria::operator=( const AMateria& other )
{
	// std::cout << "AMateria Copy assignment called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return(*this);
}

AMateria::~AMateria( void ) {
	// std::cout << "AMateria Destructor called" << std::endl;
}

const std::string& AMateria::getType() const
{
	return this->_type;
}

AMateria* AMateria::clone() const
{
	return NULL;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
