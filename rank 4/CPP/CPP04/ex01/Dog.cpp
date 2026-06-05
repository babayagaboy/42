/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:49:46 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/02 16:50:38 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	this->_brain = new Brain();
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog( const Dog& other )
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=( const Dog& other )
{
	std::cout << "Dog Copy assignment called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

void	Dog::makeSound( void ) const {
	std::cout << "*bark bark*" << std::endl;
}

Brain*	Dog::getBrain( void ) {
	return(this->_brain);
}