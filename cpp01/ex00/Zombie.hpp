/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:57:12 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 15:33:57 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void) const;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif

