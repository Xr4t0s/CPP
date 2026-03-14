NAME    = PmergeMe

SRC_DIR = src
OBJ_DIR = build

SRC     = $(shell find $(SRC_DIR) -name "*.cpp")
OBJ     = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -g
INC     = -I include

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re