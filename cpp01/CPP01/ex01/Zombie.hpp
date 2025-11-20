/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:36:52 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 16:00:24 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie
{
    std::string name;

public:
    Zombie();
    ~Zombie();
    void setName(std::string name);
    void announce(void) const;
};

Zombie *zombieHorde(int N, std::string name);
#endif

