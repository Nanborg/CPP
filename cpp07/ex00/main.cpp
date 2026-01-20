/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:55:17 by marvin            #+#    #+#             */
/*   Updated: 2026/01/20 14:55:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include "whatever.hpp"


class Awesome {
public:
	Awesome(void) : _n(0) {}
	Awesome( int n ) : _n( n ) {}
	Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
	bool operator==( Awesome const & other ) const { return (this->_n == other._n); }
	bool operator!=( Awesome const & other ) const{ return (this->_n != other._n); }
	bool operator>( Awesome const & other ) const { return (this->_n > other._n); }
	bool operator<( Awesome const & other ) const { return (this->_n < other._n); }
	bool operator>=( Awesome const & other ) const { return (this->_n >= other._n); }
	bool operator<=( Awesome const & other ) const { return (this->_n <= other._n); }
	int get_n() const { return _n; }
private:
	int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void) 
{

	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	Awesome obj1(10);
	Awesome obj2(20);

	::swap(obj1, obj2);
	std::cout << "obj1 = " << obj1 << ", obj2 = " << obj2 << std::endl;
	std::cout << "min(obj1, obj2) = " << ::min(obj1, obj2) << std::endl;
	std::cout << "max(obj1, obj2) = " << ::max(obj1, obj2) << std::endl;

	int e = 42;
	int f = 42;

	std::cout << "e addr: " << &e << std::endl;
	std::cout << "f addr: " << &f << std::endl;
	std::cout << "min addr: " << &::min(e, f) << " (should be = f)" << std::endl;
	std::cout << "max addr: " << &::max(e, f) << " (should be = f)" << std::endl;

	return 0;
}