/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:06:26 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/01 20:16:16 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap("Deafult")
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdmg = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdmg = 20;
}

ScavTrap::ScavTrap( ScavTrap& other ) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& other)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energypoints = other._energypoints;
		this->_attackdmg = other._attackdmg;
	}
	return (*this);
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::attack( const std::string& target )
{
	if (this->_energypoints > 0)
	{
		std::cout <<
		"ScavTrap " << this->_name << " attacks " <<
		target << ", causing " << this->_attackdmg <<
		" points of damage!"
		<< std::endl;
		this->_energypoints--;
	}
	else
	{
		std::cout <<
		"ScavTrap " << this->_name << " is already tired"
		<< ", cant attack."
		<< std::endl;
	}
}

void	ScavTrap::takeDamage( unsigned int amount )
{
	if(this->_hitpoints > 0)
	{
		std::cout <<
		"ScavTrap " << this->_name << " took " <<
		amount << " points of damage!"
		<< std::endl;
		this->_hitpoints -= amount;
		if (this->_hitpoints <= 0)
		{
			std::cout <<
			"ScavTrap " << this->_name << " died."
			<< std::endl;
		}
	}
	else
	{
		std::cout <<
		"ScavTrap " << this->_name << " is already dead."
		<< std::endl;
	}
}

void	ScavTrap::beRepaired( unsigned int amount )
{
	if(this->_energypoints > 0)
	{
		std::cout <<
		"ScavTrap " << this->_name << " repaired " <<
		amount << " hit points!"
		<< std::endl;
		this->_energypoints--;
		this->_hitpoints += amount;
	}
	else
	{
		std::cout <<
		"ScavTrap " << this->_name << " is already tired"
		<< ", cant be repaired."
		<< std::endl;
	}
}

void ScavTrap::guardGate( void ) {
	std::cout << this->_name << " is now in Gatekeeper mode." << std::endl;
}