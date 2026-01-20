NAME = ex01
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = Serializer.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Serializer.hpp Data.hpp

all: $(NAME)

$(OBJS): $(HEADERS)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re