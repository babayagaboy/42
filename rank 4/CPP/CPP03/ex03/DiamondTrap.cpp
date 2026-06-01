/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:28:30 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/01 20:28:30 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap ( void ) : ClapTrap("Default_clap_name"), ScavTrap("Default"),
	FragTrap("Default"), _name("Default") 
{
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energypoints = ScavTrap::_energypoints;
	this->_attackdmg = FragTrap::_attackdmg;
}

DiamondTrap::DiamondTrap ( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name),
	FragTrap(name), _name(name) 
{
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energypoints = ScavTrap::_energypoints;
	this->_attackdmg = FragTrap::_attackdmg;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::takeDamage( unsigned int amount )
{
	if(this->_hitpoints > 0)
	{
		std::cout <<
		"DiamondTrap " << this->_name << " took " <<
		amount << " points of damage!"
		<< std::endl;
		this->_hitpoints -= amount;
		if (this->_hitpoints <= 0)
		{
			std::cout <<
			"DiamondTrap " << this->_name << " died."
			<< std::endl;
		}
	}
	else
	{
		std::cout <<
		"DiamondTrap " << this->_name << " is already dead."
		<< std::endl;
	}
}

void	DiamondTrap::beRepaired( unsigned int amount )
{
	if(this->_energypoints > 0)
	{
		std::cout <<
		"DiamondTrap " << this->_name << " repaired " <<
		amount << " hit points!"
		<< std::endl;
		this->_energypoints--;
		this->_hitpoints += amount;
	}
	else
	{
		std::cout <<
		"DiamondTrap " << this->_name << " is already tired"
		<< ", cant be repaired."
		<< std::endl;
	}
}

void DiamondTrap::whoAmI( void )
{
    std::cout << "DiamondTrap name: " << this->_name 
              << ", and my ClapTrap name is: " << ClapTrap::_name << std::endl;
}