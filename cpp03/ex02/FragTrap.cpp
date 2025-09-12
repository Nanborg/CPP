/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:28:47 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 14:53:51 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    // Initialisation des valeurs spécifiques à FragTrap
    this->name = "Frag_noname";
    this->health = 100;
    this->moves = 100;
    this->dmg = 30;
    std::cout << "[FT Constructor] (" << this->name << ")\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) // Correction : Appel au constructeur parent
{
    // Initialisation des valeurs spécifiques à FragTrap
    this->health = 100;
    this->moves = 100;
    this->dmg = 30;
    std::cout << "[FT Constructor] (" << this->name << ")\n";
}

FragTrap::FragTrap(const FragTrap &o) : ClapTrap(o) // Correction : Appel au constructeur de copie parent
{
    *this = o;
    std::cout << "[FT Copy Constructor] (" << this->name << ")\n";
}

FragTrap &FragTrap::operator=(const FragTrap &o)
{
    std::cout << "[FT Assignment Operator] called for " << this->name << "\n";
    if (this != &o)
    {
        ClapTrap::operator=(o); // Correction : Appel à l'opérateur du parent
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "[FT Destructor] (" << this->name << ")\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " requests a positive high five!\n";
}