/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:23:53 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/26 19:23:53 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	{
		const Point a;
		const Point b(10, 0);
		const Point c(0, 10);
		const Point point(1, 1);

		std::cout << "The point( x= " << point.getX() << "\t\ty= " << point.getY() << "\t) is inside the triangle\n" <<
		"\ta( x= " << a.getX() << "\t\ty= " << a.getY() << "\t)\n" <<
		"\tb( x= " << b.getX() << "\ty= " << b.getY() << "\t)\n" <<
		"\tc( x= " << c.getX() << "\t\ty= " << c.getY() << "\t)\n" << std::endl;
		if (bsp(a, b, c, point) == true)
			std::cout << "TRUE" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
	}
	{
		Point a(-1.5, -1.5);
		Point b(2.5, 2.5);
		Point c(-1, -2);
		Point point(8.5, -9);

		std::cout << "The point( x= " << point.getX() << "\ty= " << point.getY() << "\t) is inside the triangle\n" <<
		"\ta( x= " << a.getX() << "\ty= " << a.getY() << "\t)\n" <<
		"\tb( x= " << b.getX() << "\ty= " << b.getY() << "\t)\n" <<
		"\tc( x= " << c.getX() << "\ty= " << c.getY() << "\t)\n" << std::endl;
		if (bsp(a, b, c, point) == true)
			std::cout << "TRUE" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		}
	return (0);
}