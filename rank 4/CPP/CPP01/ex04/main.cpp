/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:56:17 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/25 17:56:17 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static inline std::string ft_replace(std::string str, std::string s1, std::string s2) {
	size_t	i;

	if (s1.empty())
		return (str);
	i = str.find(s1);
	while (i != std::string::npos)
	{
		str = str.substr(0, i) + s2 + str.substr(i + s1.length());
		i = str.find(s1, i + s2.length());
	}
	return (str);
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Wrong number of arguments! <filename> <s1> <s2>\n", 1);
	
	std::string str;
	std::string filename(av[1]);
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::string filenamecpy(filename + "_copy");

	std::fstream file(filename.c_str(), std::ios::in);
	std::fstream filecpy(filenamecpy.c_str(), std::ios::out);

	while (std::getline(file, str))
		filecpy << ft_replace(str, s1, s2) << std::endl;
	return (0);
}
