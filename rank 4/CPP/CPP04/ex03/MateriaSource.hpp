/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 23:00:00 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 23:00:00 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _knownMaterias[4];
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource& other );
		MateriaSource& operator=( const MateriaSource& other );
		virtual ~MateriaSource( void );

		virtual void learnMateria( AMateria* m );
		virtual AMateria* createMateria( const std::string& type );
};

#endif
