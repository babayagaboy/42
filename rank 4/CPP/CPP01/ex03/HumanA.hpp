/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:33:22 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/22 21:27:53 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon &_weapon;
	public:
		HumanA( std::string name, Weapon &weapon);
		~HumanA( void );
		void	attack( void );
};

#endif