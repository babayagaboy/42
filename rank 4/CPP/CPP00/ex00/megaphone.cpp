/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:53:57 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/18 20:30:21 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for(int i = 1; i < ac; i++) {
		for (int j = 0; av[i][j]; j++) {
			std::cout << (std::isalpha(av[i][j]) ? static_cast<char>(std::toupper(static_cast<int>(av[i][j]))) : av[i][j]);
		}
	}
	std::cout << std::endl;
}