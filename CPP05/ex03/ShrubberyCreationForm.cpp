/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:55:50 by marvin            #+#    #+#             */
/*   Updated: 2025/12/24 13:55:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) 
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execAction() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (ofs.is_open()) 
    {
        ofs << "                          XXX                            \n";
        ofs << "                          XXX                            \n";
        ofs << "                          XXX                            \n";
        ofs << "                          XXX                            \n";
        ofs << "                XXXXXXXXXXXXXXXXXXXXXXX                  \n";
		ofs << "                         XXXXX                           \n";
        ofs << "                        XXXXXXX                          \n";
		ofs << "                      XX  XXX  XX                        \n";
		ofs << "                  XXX     XXX    XXX                     \n";
		ofs << "              XXXXX       XXX      XXXXX                 \n";
		ofs << "                          XXX                            \n";
		ofs << "              XXX         XXX         XXX                \n";
		ofs << "              XXX                     XXX                \n";
		ofs << "              XXX                     XXX                \n";
		ofs << "     XXXXXXXXXXXXXXXXXXXXX    XXXXXXXXXXXXXXXXXXXX       \n";
		ofs << "             XXXXX                   XXXXX               \n";
		ofs << "            XXXXXXX                 XXXXXXX              \n";
		ofs << "           XX XXX XX               XX XXX XX             \n";
		ofs << "         XX   XXX   XX           XX   XXX   XX           \n";
		ofs << "       XX     XXX              XX     XXX     XX         \n";
		ofs << "     XX       XXX            XX       XXX       XX       \n";
		ofs << "              XXX                     XXX                \n";
		ofs << "                                                         \n";
        ofs.close();
    }
}
