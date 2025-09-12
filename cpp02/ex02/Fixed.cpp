/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:19:25 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/10 19:54:01 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : Bits(0) {}
Fixed::Fixed(const Fixed &other) : Bits(other.Bits) {}
Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        Bits = other.Bits;
    return *this;
}
Fixed::~Fixed() {}

Fixed::Fixed(int const n) : Bits(n << f_Bits) {}
Fixed::Fixed(float const f) : Bits(static_cast<int>(roundf(f * (1 << f_Bits)))) {}

float Fixed::toFloat() const { return static_cast<float>(Bits) / static_cast<float>(1 << f_Bits); }
int Fixed::toInt() const { return Bits >> f_Bits; }

int Fixed::getRawBits() const { return Bits; }
void Fixed::setRawBits(int const raw) { Bits = raw; }

bool Fixed::operator>(const Fixed &arg) const { return Bits > arg.Bits; }
bool Fixed::operator<(const Fixed &arg) const { return Bits < arg.Bits; }
bool Fixed::operator>=(const Fixed &arg) const { return Bits >= arg.Bits; }
bool Fixed::operator<=(const Fixed &arg) const { return Bits <= arg.Bits; }
bool Fixed::operator==(const Fixed &arg) const { return Bits == arg.Bits; }
bool Fixed::operator!=(const Fixed &arg) const { return Bits != arg.Bits; }

Fixed Fixed::operator+(const Fixed &arg) const
{
    Fixed r;
    r.Bits = Bits + arg.Bits;
    return r;
}

Fixed Fixed::operator-(const Fixed &arg) const
{
    Fixed r;
    r.Bits = Bits - arg.Bits;
    return r;
}

Fixed Fixed::operator*(const Fixed &arg) const
{
    Fixed r;
    long tmp = static_cast<long>(Bits) * static_cast<long>(arg.Bits);
    r.Bits = static_cast<int>(tmp >> f_Bits);
    return r;
}

Fixed Fixed::operator/(const Fixed &arg) const
{
    Fixed r;
    long num = (static_cast<long>(Bits) << f_Bits);
    r.Bits = static_cast<int>(num / arg.Bits);
    return r;
}

Fixed &Fixed::operator++()
{
    ++Bits;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++Bits;
    return tmp;
}

Fixed &Fixed::operator--()
{
    --Bits;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --Bits;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

/*
Implémentation Fixed :
- Constructeurs : défaut, copie, int→fixed, float→fixed.
- Opérateurs comparaison : > < >= <= == != (comparaison directe de Bits).
- Opérateurs arithmétiques :
+ / - : addition/soustraction directe.
 et * : multiplication avec cast long et >> f_Bits pour conserver précision.
/ : division avec << f_Bits sur numérateur.
- Incrémentation/décrémentation : préfixe (modifie et retourne *this), postfixe (retourne copie avant modif).
- Fonctions statiques min/max : retournent la plus petite/grande valeur.
- operator<< : affiche en float.
*/
