NAME = minishell
INC = includes/libft.h includes/parsing.h \
	includes/utils_char_str.h includes/execution.h

SRCS_LIBFT = src/libft/utils1.c src/libft/utils2.c src/libft/utils3.c \
	src/libft/utils4.c src/libft/utils5.c src/libft/utils6.c src/libft/ft_split.c

SRC_PRS = src/parsing/tokenizer.c src/parsing/parser1.c src/parsing/parser2.c \
	src/parsing/exec_list_utils1.c src/parsing/exec_list_utils2.c src/parsing/expander1.c \
	src/parsing/expander2.c src/parsing/expander2_utils.c src/parsing/expander3.c


SRC_EXEC = src/execution/exec_redirections1.c src/execution/other_exec.c \
	src/execution/redirection.c src/execution/execution.c src/execution/error_msg.c \
	src/execution/exec_cmd.c

SRC_BUIL = src/builtins/built_cd.c src/builtins/built_echo.c src/builtins/built_env.c \
	src/builtins/built_exit.c src/builtins/built_export.c src/builtins/built_pwd.c \
	src/builtins/built_unset.c src/builtins/its_builtins.c src/builtins/other_built_export.c
	
SRC_ENV =  src/environment/environment.c src/environment/get_env.c src/environment/other_env.c

SRC_SIG = src/signals/signals1.c


SRCS = $(SRCS_LIBFT) $(SRC_PRS) $(SRC_EXEC) $(SRC_ENV) $(SRC_BUIL) $(SRC_SIG)\
src/main.c src/free_grb.c

CFLAGS = -Wall -Werror -Wextra  -I/goinfre/ibenmain/homebrew/opt/readline/include
CC = cc
RM = rm
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lreadline -L/goinfre/ibenmain/homebrew/opt/readline/lib -o $(NAME) $^

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all