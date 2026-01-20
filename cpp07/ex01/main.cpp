/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:55:26 by marvin            #+#    #+#             */
/*   Updated: 2026/01/20 14:55:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Iter.hpp"

class Awesome
{
    public:
        Awesome( void ) : _size( 42 ) 
        {
            return;
        }
        int get( void ) const 
        { 
            return this->_size; 
        }
    private:
        int _size;
};

std::ostream & operator<<( std::ostream & o, Awesome const & other ) 
{ 
    o << other.get(); 
    return o; 
}

template< typename T >
void    print( T const & x ) 
{
    std::cout << x << std::endl;
    return;
}

void increment(int & x)
{
    x++;
}

int main()
{
    int tab[] = { 0, 1, 2, 3, 4 };
    iter( tab, 5, print );
    iter( tab, 5, increment );
    iter( tab, 5, print );
    Awesome tab2[5];
    iter( tab2, 5, print );
    return 0;
}