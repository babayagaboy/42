/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:20:51 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/11 15:20:51 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {
	private:
		T				*_arr;
		unsigned int	_size;
	public:
		Array( void );
		Array( unsigned int n );
		Array( const Array& other );
		Array& operator=( const Array& other );
		~Array( void );

		T& operator[]( unsigned int index );
		const T& operator[]( unsigned int index ) const;

		unsigned int size( void ) const;
};

# include "Array.tpp"

#endif