NAME    = iter
SRC     = src/main.cpp

OBJ_DIR = build
OBJ     = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

CXX     = c++
CF      = -Wall -Wextra -Werror -std=c++98 -g
INC     = -I include/

all: $(NAME)

$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	$(CXX) $(CF) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CF) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re