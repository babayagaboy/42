/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:04:28 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/09 15:29:32 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {}
Serializer::Serializer( const Serializer& other )
{
	(void)other;
}
Serializer& Serializer::operator=( const Serializer& other )
{
	if (this != &other) {}
	return (*this);
}
Serializer::~Serializer( void ) {}


uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}