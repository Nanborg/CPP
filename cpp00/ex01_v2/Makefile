# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 11:45:23 by nicolsan          #+#    #+#              #
#    Updated: 2025/09/13 18:37:59 by nicolsan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
GCC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

%.o: %.cpp Contact.hpp PhoneBook.hpp
	${GCC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
