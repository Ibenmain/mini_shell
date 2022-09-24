NAME = minishell
INC = includes/libft.h includes/parsing.h \
	includes/utils_char_str.h includes/execution.h

SRCS = src/libft/utils1.c src/libft/utils2.c src/libft/utils3.c\
	src/libft/utils4.c  src/libft/utils5.c src/libft/utils6.c \
	src/parsing/tokenizer.c src/parsing/parser1.c src/parsing/parser2.c \
	src/parsing/exec_list_utils1.c src/parsing/exec_list_utils2.c \
	src/execution/exec_redirections1.c src/main.c src/execution/signal.c \
	src/environment/environment.c src/builtins/its_builtins.c \
	src/builtins/built_env.c src/builtins/built_pwd.c \
	src/builtins/built_cd.c src/builtins/built_exit.c \
	src/builtins/built_echo.c src/environment/get_env.c \
	src/builtins/built_unset.c src/builtins/built_export.c \
	src/builtins/other_built_export.c src/execution/execution.c src/execution/signal.c \
	src/execution/signal.c src/execution/other_exec.c

CFLAGS = -Wall -Werror -Wextra -g
CC = cc
RM = rm -rf
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