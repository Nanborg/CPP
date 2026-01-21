NAME = ex00
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = 
OBJS = $(SRCS:.cpp=.o)
HEADERS = 

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