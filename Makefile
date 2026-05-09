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

PRIMITIVES_SRC	= 	src/Object/Primitive/Sphere/Sphere.cpp \
					src/Object/Primitive/Rectangle3D/Rectangle3D.cpp \
					src/Object/Primitive/Plane/Plane.cpp \
					src/Object/Primitive/Cylinder/Cylinder.cpp \
					src/Object/Primitive/Cone/Cone.cpp \

PRIMITIVES_INCLUDE =	src/Object/Primitive/IPrimitive/IPrimitive.hpp \
						src/Object/Primitive/Sphere/Sphere.hpp \
						src/Object/Primitive/Rectangle3D/Rectangle3D.hpp \
						src/Object/Primitive/Plane/Plane.hpp \
						src/Object/Primitive/Cylinder/Cylinder.hpp \
						src/Object/Primitive/Cone/Cone.hpp \

LIGHTS_SRC		=	src/Object/Light/PointLight/PointLight.cpp \
					src/Object/Light/DirectionalLight/DirectionalLight.cpp

LIGHTS_INCLUDE	=	src/Object/Light/ILight/ILight.hpp \
					src/Object/Light/PointLight/PointLight.hpp \
					src/Object/Light/DirectionalLight/DirectionalLight.hpp

SRC     =   src/main.cpp \
			src/Parser/Parser.cpp \
			src/Core/Core.cpp \
			src/Math/Point3D/Point3D.cpp \
			src/Math/Vector3D/Vector3D.cpp \
			src/Object/Ray/Ray.cpp \
			src/Scene/Scene.cpp \
			src/Object/Camera/Camera.cpp \
			$(PRIMITIVES_SRC) \
			$(LIGHTS_SRC)
			

INCLUDE =   include/Raytracer.hpp \
			src/Include/RTCError.hpp \
			src/Parser/Parser.hpp \
			src/Core/Core.hpp \
			src/Scene/Scene.hpp \
			src/Math/Point3D/Point3D.hpp \
			src/Math/Vector3D/Vector3D.hpp \
			src/Object/Ray/Ray.hpp \
			src/Object/Camera/Camera.hpp \
			$(PRIMITIVES_INCLUDE) \
			$(LIGHTS_INCLUDE)

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