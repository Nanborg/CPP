/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:53:50 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 14:48:01 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
};
#endif

/*
Rôle du fichier : Ce fichier d'en-tête déclare la classe ScavTrap en tant que classe dérivée de ClapTrap. C'est ici que le concept d'héritage est mis en œuvre.
Syntaxe de l'Héritage : La ligne class ScavTrap : public ClapTrap signifie que ScavTrap est un type spécial de ClapTrap. Elle hérite de tous les membres public et protected de ClapTrap (ses attributs et ses fonctions comme takeDamage et beRepaired).
Spécialisation : En plus de ce qu'elle hérite, ScavTrap se spécialise en déclarant ses propres fonctions.
void attack(const std::string &target); : ScavTrap redéfinit la fonction attack. Grâce au mot-clé virtual dans la classe de base, cela est fait de manière polymorphique, permettant à un ScavTrap d'avoir un comportement d'attaque différent.
void guardGate(); : ScavTrap introduit une nouvelle capacité qui lui est propre et qui n'existe pas dans la classe ClapTrap.
Forme Canonique : La classe déclare son propre ensemble de constructeurs et son destructeur pour gérer correctement son cycle de vie.
*/