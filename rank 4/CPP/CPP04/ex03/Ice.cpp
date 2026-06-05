/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:16:42 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 19:42:39 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
	// std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice( const Ice& other ) : AMateria( *this )
{
	// std::cout << "Ice Copy constructor called" << std::endl;
	*this = other;
}

Ice& Ice::operator=( const Ice& other )
{
	// std::cout << "Ice Copy assignment called" << std::endl;
	if(this != &other)
		this->_type = other._type;
	return(*this);
}

Ice::~Ice( void ) {
	// std::cout << "Ice Destructor called" << std::endl;
}

AMateria* Ice::clone( void ) const {
	return( new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}