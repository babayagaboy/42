/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:26:50 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/01 20:22:43 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
	FragTrap a("hugo");
	a.attack("vlad");
	a.takeDamage(5);
	a.beRepaired(10);
	a.takeDamage(500);
	a.highFivesGuys();
}