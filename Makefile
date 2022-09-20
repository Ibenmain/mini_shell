NAME = minishell
INC = includes/libft.h includes/parsing.h \
	includes/utils_char_str.h includes/execution.h

SRCS = src/libft/utils1.c src/libft/utils2.c src/libft/utils3.c \
	src/parsing/tokenizer.c src/parsing/parser1.c src/parsing/parser2.c \
	src/parsing/exec_list_utils1.c src/parsing/exec_list_utils2.c \
	src/execution/exec_redirections1.c src/main.c

CFLAGS = -Wall -Werror -Wextra -g
CC = cc
RM = rm
READLINE = -lreadline
OBJS = $(SRCS:.c=.o)

#directory for library files
#READ_LINE_LIB = ~/goinfre/.brew/opt/readline/lib
READ_LINE_LIB = /goinfre/kfaouzi/homebrew/opt/readline/lib

#include directory of header files
#READ_LINE_INC = ~/goinfre/.brew/opt/readline/include
READ_LINE_INC = /goinfre/kfaouzi/homebrew/opt/readline/include

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(READLINE) -L $(READ_LINE_LIB) -I $(READ_LINE_INC)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(READ_LINE_INC)

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re:fclean all