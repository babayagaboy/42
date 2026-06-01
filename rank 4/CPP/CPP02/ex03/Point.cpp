/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 09:21:23 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/01 09:21:23 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
	//std::cout << "Point Default constructor called" << std::endl;
}

Point::Point( const float x, const float y) : _x(x), _y(y) {
	//std::cout << "Point Two Points constructor called" << std::endl;
}

Point::Point( const Point& other)
{
	this->operator=(other);
	//std::cout << "Point Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other)
{
	this->_x = other._x;
	this->_y = other._y;
	return(*this);
}

Point::~Point( void ) {
	//std::cout << "Point destructor called" << std::endl;
}

const Fixed& Point::getX() const {
	return(this->_x);
}
const Fixed& Point::getY() const {
	return(this->_y);
}

std::ostream &operator<<(std::ostream &o, const Point &point)
{
	o << "_x: " << point.getX() << " | _y: " << point.getY();
	return (o);
}