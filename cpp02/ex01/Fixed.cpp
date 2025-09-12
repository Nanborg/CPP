/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:04:24 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/10 19:54:01 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : Bits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : Bits(other.Bits)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->Bits = other.Bits;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const number)
{
    std::cout << "Int constructor called" << std::endl;
    Bits = number << f_Bits;
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    Bits = static_cast<int>(roundf(value * (1 << f_Bits)));
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return Bits;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    Bits = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(Bits) / static_cast<float>(1 << f_Bits);
}

int Fixed::toInt() const
{
    return Bits >> f_Bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

/*
Implémentation Fixed :
- Constructeurs : défaut, copie, int→fixed (<<), float→fixed (roundf).
- Opérateur = : copie Bits (avec auto-affectation).
- Destructeur : message debug.
- get/setRawBits : accès brut.
- toFloat / toInt : conversions inverses.
- operator<< : affiche en float.
*/
