/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:42:13 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 19:53:39 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource( void )
{
	// std::cout << "IMateriaSource Default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource( const IMateriaSource& other )
{
	// std::cout << "IMateriaSource Copy constructor called" << std::endl;
	(void)other;
}

IMateriaSource& IMateriaSource::operator=( const IMateriaSource& other )
{
	// std::cout << "IMateriaSource Copy assignment called" << std::endl;
	(void)other;
	return (*this);
}

IMateriaSource::~IMateriaSource( void )
{
	// std::cout << "IMateriaSource Destructor called" << std::endl;
}

