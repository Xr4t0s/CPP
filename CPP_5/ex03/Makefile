NAME    = intern
SRC     = 	src/main.cpp \
			src/office/Bureaucrat.cpp \
			src/office/Intern.cpp \
			src/forms/AForm.cpp \
			src/forms/ShrubberyCreationForm.cpp \
			src/forms/RobotomyRequestForm.cpp \
			src/forms/PresidentialPardonForm.cpp

OBJ     = $(SRC:.cpp=.o)
CXX     = c++
CF      = -Wall -Wextra -Werror -std=c++98 -g
INC     = -I include/

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CF) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CF) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf *_shrubbery

re: fclean all

.PHONY: all clean fclean re