/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:29:46 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 17:31:13 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *brain;

public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    virtual ~Cat();

    virtual void makeSound() const;
};
#endif