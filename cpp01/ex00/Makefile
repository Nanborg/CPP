
NAME = braiiiiiiinnnzzzZ

GCC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98


SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp


OBJS = $(SRCS:.cpp=.o)


all: $(NAME)


$(NAME): $(OBJS)
	$(GCC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re