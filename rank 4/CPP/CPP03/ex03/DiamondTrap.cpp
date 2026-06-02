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

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap(other), ScavTrap(other),
	FragTrap(other)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other )
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energypoints = other._energypoints;
		this->_attackdmg = other._attackdmg;
	}
	return (*this);
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