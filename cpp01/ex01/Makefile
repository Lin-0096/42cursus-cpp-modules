NAME := zombie_horde

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++20

OBJ_DIR := obj
SRC := main.cpp Zombie.cpp zombieHorde.cpp
OBJ :=$(SRC:%.cpp=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
		mkdir -p $(OBJ_DIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(OBJ_DIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re
