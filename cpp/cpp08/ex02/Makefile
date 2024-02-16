NAME = ex02

CXXFLAGS = -MMD -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = main.cpp \

INC = MutantStack.tpp 

OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
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