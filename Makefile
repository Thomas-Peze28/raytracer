##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## raytracer
##

SRC     =   src/main.cpp \
			src/Core/Core.cpp \
			src/Parser/Parser.cpp \

CXX     =   g++

OBJ     =   $(SRC:.cpp=.o)

NAME    =   raytracer

HEADERS = 	-I src/Core \
			-I src/Include \
			-I src/Parser \

CXXFLAGS = -Wextra -Wall $(HEADERS) -std=c++20

RED=\033[38;5;196m
GREEN=\033[38;5;46m
BLUE=\033[38;5;21m
RESET=\033[0m

.SILENT:

all:    $(NAME)

$(NAME):    $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)
	@printf "$(GREEN)[OK] Project '$(NAME)' built successfully.$(RESET)\n"

clean:
	rm -f $(OBJ)
	@printf "$(BLUE)[INFO] Object files removed.$(RESET)\n"

fclean: clean
	rm -f $(NAME)
	@printf "$(RED)[INFO] Binary '$(NAME)' removed.$(RESET)\n"

re: fclean all