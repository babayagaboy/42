/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:49:49 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/02 16:51:20 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat( const Cat& other )
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=( const Cat& other )
{
	std::cout << "Cat Copy assignment called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void	Cat::makeSound( void ) const {
	std::cout << "*meow meow*" << std::endl;
}

Brain*	Cat::getBrain( void ) {
	return(this->_brain);
}