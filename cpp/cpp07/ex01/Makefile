NAME = ex01

CXXFLAGS = -MMD -Wall -Wextra -Werror -std=c++98 -g3

CXX = c++

SRC = main.cpp \

OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ) $(DEP)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY : clean fclean re all

-include $(DEP)