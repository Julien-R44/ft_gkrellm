NAME	= HumanGL
DEBUG	= yes
ifeq ($(DEBUG),no)
	FLAGS=-Wall -Wextra -Werror
else
	FLAGS= -g
endif
CC		= g++
SRC		= \
			main.cpp \
			Skeleton.cpp

OBJ		= $(SRC:.cpp=.o)
SRCDIR	= ./src/
OBJDIR	= ./obj/
INCDIR	= ./inc/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))
INCS	= $(addprefix $(INCDIR), $(INC))
LDFLAGS	= -I./inc/ -I./libft/include/ -I./libmath/inc/ -I /usr/include/GL/
LIBFLAG = -lSDL2 -lGLEW -lglut -lGLU -lGL -lXmu -lX11 -lm

.SILENT:

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(FLAGS) -o $@ $^ $(LIBFLAG)
	echo "\\033[1;32mSuccess.\\033[0;39m"

$(OBJS): $(SRCS)
ifeq ($(DEBUG),yes)
	echo "\\033[1;31mDEBUG COMPILATION.. (no flags except -g)\\033[0;39m"
else
	echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
endif
	echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
	$(CC) $(FLAGS) -c $(SRCS) $(LDFLAGS)
	mkdir -p $(OBJDIR)
	mv $(OBJ) $(OBJDIR)

.PHONY: clean fclean re

clean:
	echo "\\033[1;34mDeleting objects...\\033[0;39m"
	rm -f $(OBJS)

fclean: clean
	echo "\\033[1;34mDeleting $(NAME)\\033[0;39m"
	rm -f $(NAME)

re: fclean all
