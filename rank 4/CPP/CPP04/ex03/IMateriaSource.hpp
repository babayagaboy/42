/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:42:23 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 19:52:05 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

// The source interface does not own materia storage directly.
#include <string>

class AMateria;

class IMateriaSource {
	public:
		IMateriaSource( void );
		IMateriaSource( const IMateriaSource& other );
		IMateriaSource& operator=( const IMateriaSource& other );
		virtual ~IMateriaSource( void );

		virtual void learnMateria( AMateria* m ) = 0;
		virtual AMateria* createMateria( const std::string& type ) = 0;
};

#endif