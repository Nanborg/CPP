/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:27:57 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 14:00:51 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
protected:
    std::string name;
    int health;
    int moves;
    int dmg;

public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    virtual ~ClapTrap();

    virtual void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif

/*
Rôle du fichier : Ce fichier d'en-tête sert de "plan de construction" pour la classe ClapTrap. Il définit son interface publique (les actions qu'elle peut effectuer) et sa structure interne, en déclarant tous ses attributs et fonctions membres.
Attributs protected et personnalisés : Les variables membres (name, health, moves, dmg) sont déclarées protected. C'est un choix de conception stratégique qui permet aux futures classes qui hériteront de ClapTrap d'accéder directement à ces attributs. Les noms ont été personnalisés pour être plus courts et intuitifs, améliorant la lisibilité du code.
Forme Canonique Orthodoxe : La classe respecte cette convention en déclarant un constructeur par défaut, un constructeur par copie, un opérateur d'affectation par copie et un destructeur. Cela garantit une gestion prévisible et sûre du cycle de vie de chaque objet.
Préparation à l'Héritage (virtual) : Le destructeur et la fonction attack sont déclarés avec le mot-clé virtual. C'est une anticipation cruciale pour les exercices suivants. virtual ~ClapTrap() assure que les objets des classes filles seront détruits correctement, tandis que virtual void attack() permet à ces mêmes classes de redéfinir cette fonction pour avoir un comportement d'attaque unique.

*/