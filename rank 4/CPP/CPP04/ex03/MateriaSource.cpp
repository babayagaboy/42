/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 23:10:00 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 19:50:26 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include "AMateria.hpp"

MateriaSource::MateriaSource( void )
{
	// std::cout << "MateriaSource Default constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->_knownMaterias[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
	// std::cout << "MateriaSource Copy constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->_knownMaterias[i] = NULL;
	*this = other;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other )
{
	// std::cout << "MateriaSource Copy assignment called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			if (this->_knownMaterias[i])
				delete this->_knownMaterias[i];
			this->_knownMaterias[i] = (other._knownMaterias[i]) ? other._knownMaterias[i]->clone() : NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource( void )
{
	// std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; ++i) {
		if (this->_knownMaterias[i]) {
			delete this->_knownMaterias[i];
			this->_knownMaterias[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria( AMateria* m )
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i) {
		if (!this->_knownMaterias[i])
		{
			this->_knownMaterias[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria( const std::string& type )
{
	for (int i = 0; i < 4; ++i) {
		if ((this->_knownMaterias[i]) && (this->_knownMaterias[i]->getType() == type))
			return (this->_knownMaterias[i]->clone());
	}
	return NULL;
}
