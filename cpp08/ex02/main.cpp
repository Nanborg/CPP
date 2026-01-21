/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:34:16 by marvin            #+#    #+#             */
/*   Updated: 2026/01/21 12:34:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mutStack;
    mutStack.push(7);
    mutStack.push(24);
    mutStack.push(9);
    std::cout << "TOP " << mutStack.top() << std::endl;
    mutStack.pop();
    std::cout << "SIZE " << mutStack.size() << std::endl;
    mutStack.push(0);
    mutStack.push(634);
    mutStack.push(48);
    mutStack.push(735);

    MutantStack<int>::iterator x = mutStack.begin();
    MutantStack<int>::iterator xe = mutStack.end();
    
    while (x != xe)
    {
        std::cout << *x << std::endl;
        ++x; 
    }
    std::stack<int> s(mutStack);

std::cout << "std::list " << std::endl;
    std::list<int> list_stack;
    list_stack.push_back(7);
    list_stack.push_back(24);
    list_stack.push_back(9); 
    list_stack.pop_back();    
    list_stack.push_back(0);
    list_stack.push_back(634);
    list_stack.push_back(48);
    list_stack.push_back(735);

    std::list<int>::iterator list_x = list_stack.begin();
    std::list<int>::iterator list_xe = list_stack.end();
    while (list_x != list_xe)
    {
        std::cout << *list_x << std::endl;
        ++list_x;
    }

    std::cout << "BONUS " << std::endl;
    MutantStack<int>::reverse_iterator r_x = mutStack.rbegin();
    MutantStack<int>::reverse_iterator r_xe = mutStack.rend();
    while (r_x != r_xe)
    {
        std::cout << *r_x << std::endl;
        ++r_x; 
    }
    return 0;
}