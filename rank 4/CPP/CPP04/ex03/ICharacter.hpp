/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:11:51 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 20:01:38 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>
#include "AMateria.hpp"

class AMateria;

class ICharacter {
	public:
		ICharacter( void );
		ICharacter( std::string name );
		ICharacter( const ICharacter& other );
		ICharacter& operator=( const ICharacter& other );
		virtual ~ICharacter();

		virtual const std::string&	getName() const = 0;
		virtual const AMateria*		getMateria( int idx ) const = 0;
		virtual void				equip( AMateria* m ) = 0;
		virtual void				unequip( int idx ) = 0;
		virtual void				use( int idx, ICharacter& target ) = 0;
};

#endif