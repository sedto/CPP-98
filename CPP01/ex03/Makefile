COLOR_GREEN = \033[0;32m
COLOR_RED = \033[0;31m
COLOR_RESET = \033[0m

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Moar_Brainz
SRC = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJ_DIR = obj
OBJ = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp
INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(COLOR_GREEN) Linking project...$(COLOR_RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "$(COLOR_GREEN) Compilation of $(NAME) completed successfully.$(COLOR_RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR_RED) Clean Done$(COLOR_RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_RED) fclean Done$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re