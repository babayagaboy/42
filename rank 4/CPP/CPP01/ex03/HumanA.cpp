/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:32:59 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/22 22:54:54 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) 
	: _name(name), _weapon(weapon)
{
	std::cout
		<< this->_name << ": "
		<< "was created! with "
		<< _weapon.getType() << " "
		<< "weapon!" 
		<< std::endl;
}

HumanA::~HumanA( void )
{
	std::cout
		<< this->_name << ": "
		<< "has destroyed!"
		<< std::endl;
} 

void	HumanA::attack( void )
{
	std::cout
		<< this->_name
		<< " attacks with their " 
		<< this->_weapon.getType()
		<< std::endl;
}