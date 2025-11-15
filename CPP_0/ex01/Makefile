NAME	= phonebook
SRC		= 	src/main.cpp \
			src/Contact.cpp \
			src/PhoneBook.cpp
INC		= includes
OBJ		= $(SRC:.cpp=.o)
CFLAGS	= -Wall -Wextra -Werror -std=c++98
CXX		= c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) -I $(INC) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CF) -I $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean