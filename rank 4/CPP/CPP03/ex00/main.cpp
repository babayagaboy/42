/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:26:50 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/01 18:03:53 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap a("hugo");
	a.attack("vlad");
	a.takeDamage(5);
	a.beRepaired(10);
	a.takeDamage(20);
	{
		ClapTrap a("a");
		for (int i = 0; i < 11; ++i) {
			a.attack("b");
		}
	}
}