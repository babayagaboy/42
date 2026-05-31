/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:25:51 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/26 19:25:51 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed( void ) 
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed( int value )
{
	std::cout << "Integer constructor called" << std::endl;
	this->_value = (value << this->_bits);
}

Fixed::Fixed( float value )
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::Fixed( const Fixed& other )
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(other);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment called" << std::endl;
	if(this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}