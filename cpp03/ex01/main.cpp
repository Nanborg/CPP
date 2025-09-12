/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:28:23 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 14:46:08 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ScavTrap tank("TANK");
    ClapTrap creature("creature");

    tank.attack("creature");
    creature.takeDamage(20);
    tank.guardGate();
    creature.attack("TANK");
    tank.takeDamage(0);
    tank.attack("creature");
    creature.takeDamage(20);
    std::cout << "Tank is cautious and suspicious\n";
    tank.attack("creature");
    creature.takeDamage(0);
    std::cout << "Creature is dead for sure\n";
    return 0;
}

/*
Rôle du fichier : Ce fichier sert de scénario de test pour démontrer l'héritage en action. Il met en scène à la fois un objet de la classe de base (ClapTrap) et un objet de la classe dérivée (ScavTrap) pour comparer leurs comportements.
Démonstration de l'Héritage :
Un ScavTrap ("tank") est créé, et on peut voir dans la sortie la chaîne de construction (le constructeur ClapTrap est appelé, puis celui de ScavTrap).
Le ScavTrap peut utiliser des fonctions héritées directement de ClapTrap (comme takeDamage et beRepaired) sans avoir eu besoin de les réécrire.
Démonstration de la Spécialisation :
Le ScavTrap utilise sa propre version de attack, qui est différente de celle du ClapTrap.
Il utilise sa capacité unique guardGate, qu'un ClapTrap normal ne pourrait pas appeler.
Validation du Cycle de Vie : La sortie du terminal à la fin du programme montre la chaîne de destruction correcte : chaque objet est détruit, en commençant par le destructeur de la classe la plus dérivée avant de remonter à la classe de base. Cela prouve que le cycle de vie des objets hérités est géré correctement.
*/
