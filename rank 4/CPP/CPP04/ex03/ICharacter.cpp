/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:11:47 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 19:54:13 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter( void ) {
	// std::cout << "ICharacter Default constructor" << std::endl;
}

ICharacter::ICharacter( std::string name )
{
	(void)name;
	// std::cout << "ICharacter Default constructor" << std::endl;
}

ICharacter::ICharacter( const ICharacter& other )
{
	// std::cout << "ICharacter Copy constructor" << std::endl;
	(void)other;
}

ICharacter& ICharacter::operator=( const ICharacter& other )
{
	// std::cout << "ICharacter Copy assignment" << std::endl;
	(void)other;
	return *this;
}

ICharacter::~ICharacter() {
	// std::cout << "ICharacter Destructor" << std::endl;
}