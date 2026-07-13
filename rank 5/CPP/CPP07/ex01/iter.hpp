/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:24:44 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/10 23:56:14 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename A, typename F>
void iter(A* arr, const size_t lenght, F func)
{
	if (!arr)
		return ;
	for(size_t n = 0; n < lenght; ++n) {
		func(arr[n]);
	}
}

#endif
