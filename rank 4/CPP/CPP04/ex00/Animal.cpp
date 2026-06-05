/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:07:09 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/02 15:30:10 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type("Default") {
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal( std::string type ) : _type(type) {
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal( const Animal& other )
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=( const Animal& other )
{
	std::cout << "Animal Copy assignment called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound( void ) const {
	std::cout << "*standard animal noises*" << std::endl;
}

std::string Animal::getType( void ) const {
	return(this->_type);
}