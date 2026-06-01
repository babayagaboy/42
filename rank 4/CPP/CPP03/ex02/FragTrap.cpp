/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:17:09 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/01 20:17:09 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("Deafult")
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdmg = 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdmg = 30;
}

FragTrap::FragTrap( FragTrap& other ) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=( const FragTrap& other )
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energypoints = other._energypoints;
		this->_attackdmg = other._attackdmg;
	}
	return (*this);
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::attack( const std::string& target )
{
	if (this->_energypoints > 0)
	{
		std::cout <<
		"FragTrap " << this->_name << " attacks " <<
		target << ", causing " << this->_attackdmg <<
		" points of damage!"
		<< std::endl;
		this->_energypoints--;
	}
	else
	{
		std::cout <<
		"FragTrap " << this->_name << " is already tired"
		<< ", cant attack."
		<< std::endl;
	}
}

void	FragTrap::takeDamage( unsigned int amount )
{
	if(this->_hitpoints > 0)
	{
		std::cout <<
		"FragTrap " << this->_name << " took " <<
		amount << " points of damage!"
		<< std::endl;
		this->_hitpoints -= amount;
		if (this->_hitpoints <= 0)
		{
			std::cout <<
			"FragTrap " << this->_name << " died."
			<< std::endl;
		}
	}
	else
	{
		std::cout <<
		"FragTrap " << this->_name << " is already dead."
		<< std::endl;
	}
}

void	FragTrap::beRepaired( unsigned int amount )
{
	if(this->_energypoints > 0)
	{
		std::cout <<
		"FragTrap " << this->_name << " repaired " <<
		amount << " hit points!"
		<< std::endl;
		this->_energypoints--;
		this->_hitpoints += amount;
	}
	else
	{
		std::cout <<
		"FragTrap " << this->_name << " is already tired"
		<< ", cant be repaired."
		<< std::endl;
	}
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << this->_name << " requested an highfive!" << std::endl;
}