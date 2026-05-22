/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:30:48 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/22 20:01:43 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void )
{
	this->_name = "Default";
	std::cout
		<< this->_name << ": " 
		<< "was created!"
		<< std::endl;
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
	std::cout
		<< this->_name << ": " 
		<< "was created!"
		<< std::endl;
}

Zombie::~Zombie( void )
{
	std::cout
		<< this->_name << ": "
		<< "has destroyed!"
		<< std::endl;
} 

void	Zombie::announce( void )
{
	std::cout
		<< this->_name << ": " 
		<< "BraiiiiiiinnnzzzZ..."
		<< std::endl;
}
