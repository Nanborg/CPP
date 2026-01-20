/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:12:47 by marvin            #+#    #+#             */
/*   Updated: 2026/01/20 11:12:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data	data;
	Data	*ptr = &data;
	
	ptr->i = 42;
	ptr->str = "Lausanne";
	ptr->d = 42.42;

	uintptr_t raw = Serializer::serialize(ptr);
	Data* res = Serializer::deserialize(raw);

	std::cout << "Original ptr: " << ptr << std::endl;
	std::cout << "Raw value:    " << raw << std::endl;
	std::cout << "Result ptr:   " << res << std::endl;

	if (res == ptr)
		std::cout << "Verification: OK" << std::endl;
	else
		std::cout << "Verification: KO" << std::endl;

	std::cout << "Data i:   " << res->i << std::endl;
	std::cout << "Data str: " << res->str << std::endl;
	std::cout << "Data d:   " << res->d << std::endl;

	return (0);
}