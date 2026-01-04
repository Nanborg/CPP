NAME = ex03
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = Intern.cpp main.cpp Bureaucrat.cpp Form.cpp Aform.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Intern.hpp Bureaucrat.hpp Form.hpp Aform.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

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



