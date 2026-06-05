/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:16:49 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 19:47:59 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
	// std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure( const Cure& other ) : AMateria ( *this )
{
	// std::cout << "Cure Copy constructor called" << std::endl;
	*this = other;
}

Cure& Cure::operator=( const Cure& other )
{
	// std::cout << "Cure Copy assignment called" << std::endl;
	if(this != &other)
		this->_type = other._type;
	return(*this);
}

Cure::~Cure( void ) {
	// std::cout << "Cure Destructor called" << std::endl;
}

AMateria* Cure::clone( void ) const {
	return(new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}