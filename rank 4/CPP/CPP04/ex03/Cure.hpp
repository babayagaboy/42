/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:16:35 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/03 13:54:18 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria {
	public:
		Cure( void );
		Cure( const Cure& other );
		Cure& operator=( const Cure& other );
		~Cure( void );

		virtual AMateria* clone( void ) const;
		virtual void use(ICharacter& target);
};

#endif