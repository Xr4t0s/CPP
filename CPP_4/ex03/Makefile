NAME    = interfaces
SRC     = 	src/main.cpp \
			src/materias/Ice.cpp \
			src/materias/Cure.cpp \
			src/materias/AMateria.cpp \
			src/character/Character.cpp  \
			src/sources/MateriaSource.cpp
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

re: fclean all

.PHONY: all clean fclean re