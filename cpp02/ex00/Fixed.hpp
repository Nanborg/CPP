/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:38:44 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/10 19:54:01 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int rawBits;
    static const int f_Bits = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);

    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif

/*
Classe Fixed :
- Membres : int rawBits, static const int f_Bits=8.
- Forme canonique orthodoxe (constructeur défaut, copie, opérateur=, destructeur).
- Accesseurs : getRawBits / setRawBits.
*/
