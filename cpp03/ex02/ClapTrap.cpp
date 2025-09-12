/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:28:39 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 15:19:39 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : name("noname"), health(30), moves(10), dmg(0)
{
    std::cout << "[CT Constructor] (" << name << ")\n";
}

ClapTrap::ClapTrap(const std::string &name)
    : name(name), health(30), moves(10), dmg(0)
{
    std::cout << "[CT Constructor] (" << name << ")\n";
}

ClapTrap::ClapTrap(const ClapTrap &o)
    : name(o.name), health(o.health), moves(o.moves), dmg(o.dmg)
{
    std::cout << "[CT Copy Constructor] (" << name << ")\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &o)
{
    std::cout << "[CT Assignment Operator] called for " << name << "\n";
    if (this != &o)
    {
        name = o.name;
        health = o.health;
        moves = o.moves;
        dmg = o.dmg;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "[CT Destructor] (" << name << ")\n";
}

void ClapTrap::attack(const std::string &target)
{
    if (health <= 0 || moves <= 0)
    {
        std::cout << "[CT] " << name << " cannot attack\n";
        return;
    }
    --moves;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << dmg << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (health <= 0)
    {
        std::cout << "[CT] " << name << " is already dead\n";
        return;
    }
    health -= (int)amount;
    if (health < 0)
        health = 0;
    std::cout << "[CT] " << name << " takes " << amount << " dmg (HP=" << health << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (health <= 0 || moves <= 0)
    {
        std::cout << "[CT] " << name << " cannot heal\n";
        return;
    }
    --moves;
    health += (int)amount;
    std::cout << "[CT] " << name << " heals " << amount << " (HP=" << health << ")\n";
}

/*
Rôle du fichier : Ce fichier contient l'implémentation, c'est-à-dire le "code moteur", de la classe ClapTrap. Il fournit la logique détaillée de chaque fonction déclarée dans le fichier .hpp.
Traçage du Cycle de Vie : Conformément aux exigences, chaque constructeur, l'opérateur d'affectation et le destructeur affichent des messages clairs et explicites ([Constructor], [Destructor], etc.). Cela permet de suivre et de vérifier facilement le cycle de vie de chaque objet directement depuis le terminal.
Logique de Jeu Robuste : Les fonctions d'action (attack, takeDamage, beRepaired) sont implémentées de manière robuste. Avant toute action, elles vérifient si le ClapTrap a assez de points de vie (health) et de points de mouvement (moves). Les actions attack et beRepaired consomment correctement un point de moves.
Gestion des États : La fonction takeDamage est conçue pour être sûre : elle s'assure que les points de vie ne peuvent pas devenir négatifs en les plafonnant à zéro. Les messages de sortie sont informatifs, indiquant l'état actuel de la santé après chaque action, ce qui facilite grandement le débogage et la validation.
*/