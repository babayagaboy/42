/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 09:21:15 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/01 09:21:15 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
	private:
		const	Fixed _x;
		const	Fixed _y;
	public:
		Point( void );
		Point( const float x, const float y);
		Point( const Point& other);
		Point& operator=(const Point& other);
		~Point( void );

		const Fixed& getX() const;
		const Fixed& getY() const;
};

std::ostream &operator<<(std::ostream &o, const Fixed& other);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif