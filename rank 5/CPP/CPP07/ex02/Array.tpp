/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:52:26 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/11 15:52:26 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : _arr(NULL), _size(0) {
	// std::cout << "Array Default constructor called." << std::endl;
}

template <typename T>
Array<T>::Array( unsigned int n ) : _arr(NULL), _size(n)
{
	// std::cout << "Array Default constructor called." << std::endl;
	if (n != 0)
		this->_arr = new T[n]();
}

template <typename T>
Array<T>::Array( const Array& other ) : _arr(NULL), _size(other._size)
{
	// std::cout << "Array Copy constructor called." << std::endl;
	if (this->_size != 0)
	{
		this->_arr = new T[this->_size]();
		for (unsigned int n = 0; n < this->_size; ++n) {
			this->_arr[n] = other._arr[n];
		}
	}
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=( const Array<T>& other )
{
	// std::cout << "Array Copy assignment called." << std::endl;
	if (this != &other)
	{
		delete[] this->_arr;
		this->_size = other._size;
		if (this->_size != 0)
		{
			this->_arr = new T[this->_size]();
			for (unsigned int n = 0; n < this->_size; ++n) {
				this->_arr[n] = other._arr[n];
			}
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array( void )
{
	// std::cout << "Array Destructor called." << std::endl;
	delete[] this->_arr;
}

template <typename T>
T& Array<T>::operator[]( unsigned int index )
{
	if( index > this->_size)
		throw (std::out_of_range("index is out of bounds"));
	return (this->_arr[index]);
}

template <typename T>
const T& Array<T>::operator[]( unsigned int index ) const
{
	if( index > this->_size)
		throw (std::out_of_range("index is out of bounds"));
	return (this->_arr[index]);
}

template <typename T>
unsigned int Array<T>::size() const {
	return (this->_size);
}