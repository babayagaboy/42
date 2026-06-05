/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:16:37 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/03 13:54:56 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria {
	public:
		Ice( void );
		Ice( const Ice& other );
		Ice& operator=( const Ice& other );
		~Ice( void );

		virtual AMateria* clone( void ) const;
		virtual void use(ICharacter& target);
};

#endif