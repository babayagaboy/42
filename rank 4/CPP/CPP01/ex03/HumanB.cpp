/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:42:11 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/22 22:55:39 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL)
{
	std::cout
		<< this->_name << ": "
		<< "was created! without a weapon!"
		<< std::endl;
}

HumanB::HumanB( std::string name, Weapon* weapon ) : _name(name), _weapon(weapon)
{
	std::cout
		<< this->_name << ": "
		<< "was created! with "
		<< this->_weapon->getType() << " "
		<< "weapon!" 
		<< std::endl;
}

HumanB::~HumanB( void )
{
	std::cout
		<< this->_name << ": "
		<< "has destroyed!"
		<< std::endl;
} 

void	HumanB::attack( void )
{
	if (this->_weapon != NULL)
	{
		std::cout
			<< this->_name
			<< " attacks with their " 
			<< this->_weapon->getType()
			<< std::endl;
	}
	else
	{
		std::cout
			<< this->_name
			<< " doesnt have a weapon" 
			<< std::endl;
	}
}