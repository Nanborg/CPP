/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:04:10 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 18:16:02 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const = 0; // PURE V
};
#endif
