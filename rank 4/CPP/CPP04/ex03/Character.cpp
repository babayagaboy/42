/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:12:13 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 22:32:51 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character( void ) : ICharacter("Default"), _name("Default")
{
	// std::cout << "Character Default constructor" << std::endl;
	for (int i = 0; i < 4; ++i) {
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; ++i) {
		this->_floor[i] = NULL;
	}
	this->floor_counter = 0;
}

Character::Character( std::string name ) : ICharacter(name), _name(name)
{
	// std::cout << "Character Default constructor" << std::endl;
	for (int i = 0; i < 4; ++i) {
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; ++i) {
		this->_floor[i] = NULL;
	}
	this->floor_counter = 0;
}

Character::Character( const Character& other ) : ICharacter(other), _name(other._name)
{
	// std::cout << "Character Copy constructor" << std::endl;
	for (int i = 0; i < 4; ++i) {
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; ++i) {
		this->_floor[i] = NULL;
	}
	this->floor_counter = 0;
	*this = other;
}

Character& Character::operator=( const Character& other )
{
	// std::cout << "Character Copy assignment" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		for (unsigned int i = 0; i < this->floor_counter; ++i) {
			if (this->_floor[i]) {
				delete this->_floor[i];
				this->_floor[i] = NULL;
			}
		}
		this->floor_counter = 0;
		for (int i = 0; i < 4; ++i) {
			if (this->_inventory[i]) { delete this->_inventory[i]; }
			this->_inventory[i] = (other._inventory[i]) ? other._inventory[i]->clone() : NULL;
		}
	}
	return (*this);
}

Character::~Character( void )
{
	std::cout << "Character Destructor" << std::endl;
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i]) { delete this->_inventory[i]; }
		this->_inventory[i] = NULL;
		std::cout << this->_name << ": Inventory cleared" << std::endl;
	}
	for (unsigned int i = 0; i < floor_counter; ++i) {
		if (this->_floor[i]) { delete this->_floor[i]; }
		this->_floor[i] = NULL;
		std::cout << this->_name << ": Floor cleared" << std::endl;
	}
}

const std::string&	Character::getName() const {
	return (this->_name);
}

const AMateria*		Character::getMateria( int idx ) const {
	return ((this->_inventory[idx]) ? this->_inventory[idx] : NULL);
}


void				Character::equip( AMateria* m )
{
	for (int i = 0; i < 4; ++i)	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void				Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		this->_floor[this->floor_counter++] = this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
}

void				Character::use( int idx, ICharacter& target )
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
	{
		std::cout << this->_name << ": ";
		this->_inventory[idx]->use(target);
	}
}
