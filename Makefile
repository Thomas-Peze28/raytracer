##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## Raytracer
##

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
RESET=\033[0m

SRC     =   src/main.cpp \
			src/Parser/Parser.cpp \
			src/Core/Core.cpp \
			src/Math/Point3D/Point3D.cpp \
			src/Math/Vector3D/Vector3D.cpp \
			src/Object/Ray/Ray.cpp \
			src/Scene/Scene.cpp \
			src/Object/Sphere/Sphere.cpp \
			src/Object/Rectangle3D/Rectangle3D.cpp \
			src/Object/Camera/Camera.cpp \
			src/Object/Light/Light.cpp \
			

INCLUDE =   include/Raytracer.hpp \
			src/Include/RTCError.hpp \
			src/Parser/Parser.hpp \
			src/Core/Core.hpp \
			src/Scene/Scene.hpp \
			src/Math/Point3D/Point3D.hpp \
			src/Math/Vector3D/Vector3D.hpp \
			src/Object/Ray/Ray.hpp \
			src/Object/IPrimitive/IPrimitive.hpp \
			src/Object/Sphere/Sphere.hpp \
			src/Object/Rectangle3D/Rectangle3D.hpp \
			src/Object/Camera/Camera.hpp \
			src/Object/Light/Light.hpp	\

CXX     =   g++

OBJ     =   $(SRC:.cpp=.o)

NAME    =   raytracer

CXXFLAGS = -Wextra -Wall $(addprefix -I, $(sort $(dir $(INCLUDE)))) -std=c++20

LDLIBS   = -lm

.SILENT:

all:    $(NAME)

$(NAME):    $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDLIBS)
	@printf "$(GREEN)[OK]$(RESET) Binary $(CYAN)'$(NAME)'$(RESET) compiled successfully.\n"

clean:
	rm -f $(OBJ)
	@printf "$(YELLOW)[INFO]$(RESET) Object files removed.\n"

fclean: clean
	rm -f $(NAME)
	@printf "$(YELLOW)[INFO]$(RESET) Binary $(CYAN)'$(NAME)'$(RESET) removed.\n"

re:     fclean all
		@printf "$(BLUE)[INFO]$(RESET) Project rebuilt successfully.\n"

.PHONY: all clean fclean re tests_run clean_tests