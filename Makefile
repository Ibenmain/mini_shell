NAME = minishell
INC = includes/libft.h includes/parsing.h \
	includes/utils_char_str.h includes/execution.h

SRCS_LIBFT = src/libft/utils1.c src/libft/utils2.c src/libft/utils3.c \
	src/libft/utils4.c src/libft/utils5.c src/libft/utils6.c src/libft/ft_split.c

SRC_PRS = src/parsing/tokenizer.c src/parsing/parser1.c src/parsing/parser2.c \
	src/parsing/exec_list_utils1.c src/parsing/exec_list_utils2.c src/parsing/expander1.c \
	src/parsing/expander2.c


SRC_EXEC = src/execution/exec_redirections1.c src/execution/other_exec.c \
	src/execution/redirection.c src/execution/execution.c src/execution/error_msg.c \
	src/execution/exec_cmd.c

SRC_BUIL = src/builtins/built_cd.c src/builtins/built_echo.c src/builtins/built_env.c \
	src/builtins/built_exit.c src/builtins/built_export.c src/builtins/built_pwd.c \
	src/builtins/built_unset.c src/builtins/its_builtins.c src/builtins/other_built_export.c
	
SRC_ENV =  src/environment/environment.c src/environment/get_env.c

SRCS = $(SRCS_LIBFT) $(SRC_PRS) $(SRC_EXEC) $(SRC_ENV) $(SRC_BUIL)\
	  src/main.c

CFLAGS = -Wall -Werror -Wextra -g #-static-libsan -fsanitize=address
CC = cc
RM = rm
READLINE = -lreadline
OBJS = $(SRCS:.c=.o)

#directory for library files
READ_LINE_LIB = ~/goinfre/.brew/opt/readline/lib
#READ_LINE_LIB = /goinfre/kfaouzi/homebrew/opt/readline/lib

#include directory of header files
READ_LINE_INC = ~/goinfre/.brew/opt/readline/include
#READ_LINE_INC = /goinfre/kfaouzi/homebrew/opt/readline/include

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(READLINE) -L $(READ_LINE_LIB) -I $(READ_LINE_INC)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(READ_LINE_INC)

run:
	make && make clean && clear && ./minishell

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all