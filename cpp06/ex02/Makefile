NAME = ex02
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = Base.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Base.hpp A.hpp B.hpp C.hpp

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