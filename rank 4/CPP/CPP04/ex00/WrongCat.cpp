/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:34:24 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/02 15:34:26 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other )
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=( const WrongCat& other )
{
	std::cout << "WrongCat Copy assignment called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "*wrong meow meow*" << std::endl;
}