/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:28:35 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/01 20:28:35 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string _name;
	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap& other );
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap( void );

		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
		using	ScavTrap::attack;
		void	whoAmI();
};

#endif