/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:16:18 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 17:11:42 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
    std::string name;
    Weapon *weapon;
public:
    HumanB(const std::string &n);
    void setWeapon(Weapon &w);
    void attack() const;
    ~HumanB();
};

#endif
