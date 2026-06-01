/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:00:02 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/01 18:36:52 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
ClapTrap::ClapTrap( void ) : _name("Default"), _hitpoints(10),
	_energypoints(10), _attackdmg(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitpoints(10),
	_energypoints(10), _attackdmg(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap& other ) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=( ClapTrap &other )
{
	std::cout << "ClapTrap Copy assigning operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;	
		this->_energypoints = other._energypoints;
		this->_attackdmg = other._attackdmg;
	}
	return (*this);	
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack( const std::string& target )
{
	if (this->_energypoints > 0)
	{
		std::cout <<
		"ClapTrap " << this->_name << " attacks " <<
		target << ", causing " << this->_attackdmg <<
		" points of damage!"
		<< std::endl;
		this->_energypoints--;
	}
	else
	{
		std::cout <<
		"ClapTrap " << this->_name << " is already tired"
		<< ", cant attack."
		<< std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if(this->_hitpoints > 0)
	{
		std::cout <<
		"ClapTrap " << this->_name << " took " <<
		amount << " points of damage!"
		<< std::endl;
		this->_hitpoints -= amount;
		if (this->_hitpoints <= 0)
		{
			std::cout <<
			"ClapTrap " << this->_name << " died."
			<< std::endl;
		}
	}
	else
	{
		std::cout <<
		"ClapTrap " << this->_name << " is already dead."
		<< std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if(this->_energypoints > 0)
	{
		std::cout <<
		"ClapTrap " << this->_name << " repaired " <<
		amount << " hit points!"
		<< std::endl;
		this->_energypoints--;
		this->_hitpoints += amount;
	}
	else
	{
		std::cout <<
		"ClapTrap " << this->_name << " is already tired"
		<< ", cant be repaired."
		<< std::endl;
	}
}