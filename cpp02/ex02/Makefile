GCC     = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME     = ex02
SRCS     = Fixed.cpp main.cpp
OBJS     = $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(GCC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
