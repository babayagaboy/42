/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:05:19 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/02 16:48:47 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain( const Brain& other )
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=( const Brain& other )
{
	std::cout << "Brain Copy assignment called" << std::endl;
	if(this != &other)
	{
		for(int i = 0; i < 100; ++i) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << "Brain Destructor called" << std::endl;
}

std::string	Brain::getIdea( int index ) {
	return(this->_ideas[index]);
}

void		Brain::setIdea( int index, std::string idea) {
	this->_ideas[index] = idea;
}
