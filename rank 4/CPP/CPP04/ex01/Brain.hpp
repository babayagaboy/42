/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:05:14 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/02 16:48:14 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain( void );
		Brain( const Brain& other );
		Brain& operator=( const Brain& other );
		~Brain( void );

		std::string	getIdea( int index );
		void		setIdea(int index, std::string idea);
};

#endif