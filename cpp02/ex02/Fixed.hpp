/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:19:22 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/10 19:54:00 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int Bits;
    static const int f_Bits = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);

    ~Fixed();
    Fixed(int const n);
    Fixed(float const f);

    float toFloat() const;
    int toInt() const;
    int getRawBits() const;
    void setRawBits(int const raw);
    bool operator>(const Fixed &arg) const;
    bool operator<(const Fixed &arg) const;
    bool operator>=(const Fixed &arg) const;
    bool operator<=(const Fixed &arg) const;
    bool operator==(const Fixed &arg) const;
    bool operator!=(const Fixed &arg) const;

    Fixed operator+(const Fixed &arg) const;
    Fixed operator-(const Fixed &arg) const;
    Fixed operator*(const Fixed &arg) const;
    Fixed operator/(const Fixed &arg) const;
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    static Fixed &min(Fixed &left, Fixed &right);
    static const Fixed &min(const Fixed &left, const Fixed &right);
    static Fixed &max(Fixed &left, Fixed &right);
    static const Fixed &max(const Fixed &left, const Fixed &right);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

/*
Classe Fixed :
- Membres : int Bits, static const int f_Bits=8.
- Constructeurs : défaut, copie, int, float.
- Opérateurs : comparaison, arithmétique, ++/--.
- Fonctions statiques : min/max (const et non-const).
- Conversions : toFloat(), toInt().
- operator<< pour affichage.
*/
