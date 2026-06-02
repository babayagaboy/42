/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:26:50 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/02 12:10:07 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	DiamondTrap a("hugo");
	DiamondTrap b(a);
	a.attack("vlad");
	a.takeDamage(5);
	a.beRepaired(10);
	a.takeDamage(500);
	a.whoAmI();

	b.attack("pider");
	b.whoAmI();
}