NAME := point

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++20 -MMD -MP

OBJ_DIR := obj
SRC := main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:
	@rm -rf $(OBJ_DIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re
