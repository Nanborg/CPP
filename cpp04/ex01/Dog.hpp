/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:25:10 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 17:26:46 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *brain;

public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    virtual ~Dog();

    virtual void makeSound() const;
};
#endif