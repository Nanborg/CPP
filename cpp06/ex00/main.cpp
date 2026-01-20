/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:44:12 by marvin            #+#    #+#             */
/*   Updated: 2026/01/20 09:44:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << " ./convert <literal>" <<std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}

/*
Tests de base
./ex00 0
./ex00 1
./ex00 42
./ex00 -42

Char affichable / non affichable
./ex00 a
./ex00 z
./ex00 ' '
./ex00 7

Int limites
./ex00 2147483647
./ex00 -2147483648
./ex00 2147483648
./ex00 -2147483649

Float valides
./ex00 42.0f
./ex00 42.5f
./ex00 -0.5f

Double valides
./ex00 42.0
./ex00 42.42
./ex00 -42.42

Pseudo-litteraux (obligatoires)
./ex00 nan
./ex00 nanf
./ex00 inf
./ex00 -inf
./ex00 +inf
./ex00 inff
./ex00 -inff
./ex00 +inff

Entrees invalides
./ex00 42ff
./ex00 42.f.f
./ex00 abc
./ex00 ""

Cas piegeux 
./ex00 127
./ex00 128
./ex00 255
./ex00 256
*/