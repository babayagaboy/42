/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:33:19 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/22 22:51:36 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		HumanB( std::string name);
		HumanB( std::string name, Weapon* weapon);
		~HumanB( void );
		void	attack( void );
};

#endif