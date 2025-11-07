/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:16:08 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 17:11:42 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
    std::string name;
    Weapon &weapon;
public:
    HumanA(const std::string &n, Weapon &w);
    void attack() const;
};

#endif


/*
HumanA : doit toujours avoir une arme.
weapon est une référence toujours valide, jamais nulle, initialisée au constructeur.
*/