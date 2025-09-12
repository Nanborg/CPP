/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:16:31 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 17:12:20 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
class Weapon
{
    std::string type;

public:
    Weapon(std::string t) : type(t) {}
    const std::string &getType() const { return type; }
    void setType(std::string t) { type = t; }
};
#endif

/*
Weapon : type privé, modifiable via setType().
getType() retourne une référence const → efficace (pas de copie) et sûr (lecture seule).
*/
