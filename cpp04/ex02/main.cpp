/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:04:31 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 18:10:28 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal *d = new Dog();
    Animal *c = new Cat();
    d->makeSound();
    c->makeSound();
    delete d;
    delete c;
}
