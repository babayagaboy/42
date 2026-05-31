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

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits;
	public:
		Fixed( void );
		Fixed( int value );
		Fixed( const Fixed& other );
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif