CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = program
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) text foo bar

.PHONY: all clean fclean re valgrind