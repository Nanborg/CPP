/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:28:27 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 14:46:08 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    name = "Scav_noname";
    health = 100;
    moves = 50;
    dmg = 20;
    std::cout << "[ST Constructor] (" << name << ")\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->health = 100;
    this->moves = 50;
    this->dmg = 20;
    std::cout << "[ST Constructor] (" << this->name << ")\n";
}

ScavTrap::ScavTrap(const ScavTrap &o) : ClapTrap(o)
{
    *this = o;
    std::cout << "[ST Copy Constructor] (" << name << ")\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &o)
{
    std::cout << "[ST Assignment Operator] called for " << name << "\n";
    if (this != &o)
    {
        ClapTrap::operator=(o);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ST Destructor] (" << name << ")\n";
}

void ScavTrap::attack(const std::string &target)
{
    if (health <= 0 || moves <= 0)
    {
        std::cout << "[ST] " << name << " cannot attack\n";
        return;
    }
    --moves;
    std::cout << "ScavTrap " << name << " fiercely attacks " << target
              << ", causing " << dmg << " points of damage!\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
}

/*
Rôle du fichier : Ce fichier implémente la logique spécifique à ScavTrap.
Chaîne de Construction (Concept Clé) : C'est le point le plus important de l'exercice. Les constructeurs de ScavTrap utilisent une liste d'initialisation pour appeler explicitement le constructeur de la classe parente (par exemple, ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)). Cette syntaxe est obligatoire pour s'assurer que la partie ClapTrap de l'objet ScavTrap est correctement construite avant que le constructeur de ScavTrap ne s'exécute.
Initialisation des attributs : Après l'appel au constructeur parent, le constructeur de ScavTrap ré-initialise les attributs hérités avec ses propres valeurs par défaut (100 HP, 50 points d'énergie, 20 de dégâts), conformément aux exigences du sujet.
Comportement Spécifique :
La fonction attack est implémentée pour afficher un message distinctif, prouvant que la redéfinition de la méthode virtuelle a fonctionné.
La fonction guardGate est implémentée, ajoutant une fonctionnalité unique à ScavTrap.
Chaîne de Destruction : Le destructeur de ScavTrap s'exécute, puis le compilateur appelle automatiquement le destructeur de la classe de base ClapTrap. C'est pourquoi la sortie du terminal montre la destruction dans l'ordre inverse de la construction ([ST Destructor] suivi de [CT Destructor]).

*/