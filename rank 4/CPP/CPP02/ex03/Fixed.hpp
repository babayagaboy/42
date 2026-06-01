/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:25:43 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/26 19:25:43 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits;
	public:
		Fixed( void );
		Fixed( const int value );
		Fixed( const float value );
		Fixed( const Fixed& other );
		Fixed&		operator=(const Fixed& other);
		~Fixed();
		
		inline bool operator>(const Fixed& other) const;
		inline bool operator<(const Fixed& other) const;
		inline bool operator>=(const Fixed& other) const;
		inline bool operator<=(const Fixed& other) const;
		inline bool operator==(const Fixed& other) const;
		inline bool operator!=(const Fixed& other) const;

		float		operator+(const Fixed& other) const;
		float		operator-(const Fixed& other) const;
		float		operator*(const Fixed& other) const;
		float		operator/(const Fixed& other) const;

		Fixed&		operator++();
		Fixed&		operator--();
		Fixed		operator++( int );
		Fixed		operator--( int );

		float		toFloat(void) const;
		int			toInt( void ) const;
		int			getRawBits(void) const;
		void		setRawBits( int const raw );

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream &operator<<(std::ostream &o, const Fixed& other);

#endif