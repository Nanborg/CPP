/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:56:58 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 15:33:57 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *heapZombie = newZombie("Foo");
    heapZombie->announce();
    delete heapZombie;
    randomChump("Bar");
    return 0;
}
