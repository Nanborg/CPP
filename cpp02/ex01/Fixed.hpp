/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:04:28 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/10 19:54:01 by nicolsan         ###   ########.fr       */
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
    Fixed(int const number);
    Fixed(float const value);

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

/*
Classe Fixed :
- Membres : int Bits, static const int f_Bits=8.
- Forme canonique + constructeurs int/float.
- Conversions : toFloat(), toInt().
- Surcharge operator<< pour affichage.
*/
