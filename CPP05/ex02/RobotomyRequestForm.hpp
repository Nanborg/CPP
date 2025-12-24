/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:25:57 by marvin            #+#    #+#             */
/*   Updated: 2025/12/24 15:25:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP


#include "Aform.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm 
{
    private:
        std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        void execAction() const;
};

#endif