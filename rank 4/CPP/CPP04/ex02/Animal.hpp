/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:07:07 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/03 13:04:32 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string	_type;
	public:
		Animal( void );
		Animal( std::string type );
		Animal( const Animal& other );
		Animal& operator=( const Animal& other );
		virtual ~Animal( void );

		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;
};

#endif