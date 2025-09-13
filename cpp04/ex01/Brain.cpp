/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:21:19 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 17:58:05 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[B] Constructor\n";
}
Brain::Brain(const Brain &o)
{
    int i = 0;
    while (i < 100)
    {
        ideas[i] = o.ideas[i];
        i++;
    }
    std::cout << "[B] Copy Constructor\n";
}
Brain &Brain::operator=(const Brain &o)
{
    if (this != &o)
    {
        int i = 0;
        while (i < 100)
        {
            ideas[i] = o.ideas[i];
            i++;
        }
    }
    std::cout << "[B] Copy Assignment\n";
    return *this;
}
Brain::~Brain()
{
    std::cout << "[B] Destructor\n";
}
