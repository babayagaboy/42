/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 22:09:52 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/25 22:09:52 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return ((std::cout << "wrong imput" << std::endl), 1);
	Harl h;
	h.complain(av[1]);
}