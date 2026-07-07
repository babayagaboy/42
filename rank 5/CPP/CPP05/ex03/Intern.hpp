/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 02:08:58 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/07 02:08:58 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern {
	public:
		Intern( void );
		Intern( const Intern& other );
		Intern& operator=( const Intern& other );
		~Intern( void );

		AForm*	makeForm( const std::string name, const std::string target);
};

#endif