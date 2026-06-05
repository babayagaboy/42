/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:12:21 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 20:12:49 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria* _inventory[4];
		AMateria* _floor[100];
		unsigned int floor_counter;
	public:
		Character( void );
		Character( std::string name );
		Character( const Character& other );
		Character& operator=( const Character& other );
		~Character( void );

		virtual const std::string&	getName() const;
		virtual const AMateria*		getMateria( int idx ) const;
		virtual void				equip( AMateria* m );
		virtual void				unequip( int idx );
		virtual void				use( int idx, ICharacter& target );
};

#endif