/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:57:08 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 15:33:57 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name)
{
} // si pas constructeur laisser comme vide

Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}
void Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/*
Zombie::Zombie(...) : constructeur avec liste d'initialisation (bonne pratique).
Zombie::~Zombie() : destructeur, ici juste un message utile au debug.
Zombie:: : indique que la méthode appartient à la classe Zombie.
*/
