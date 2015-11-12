NAME = ft_gkrellm
CFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp \
		sfmlWindowDisplayer.cpp \
		curseWindowDisplayer.cpp

all: make

make:
	g++ $(NOFLAGS) $(SRCS) -lncurses -lsfml-graphics -lsfml-window -lsfml-system -o $(NAME)

re: all

fclean:
	rm $(NAME)
