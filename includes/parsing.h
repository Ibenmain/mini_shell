/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 07:38:32 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/19 19:11:08 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H
# include "libft.h"
# include "utils_char_str.h"
# include "execution.h"

/**
 * @brief 
 * the type considered as enum 
 * of each word in the entred line
 */
typedef enum s_enum
{
	WORD,
	PIPE,
	RED,
	D_QTE,
	S_QTE,
	HEREDC,
	REDOUT,
	REDIN,
	APPND,
	NON,
}t_enum;

/**
 * @brief
 * the list that will be parsed
 * each word is the value
 * and its type
 */
typedef struct s_tok
{
	char			*value;
	t_enum			type;
	struct s_tok	*next;
}t_tok;

/**
 * @brief
 * list of all redirections for each cmd
 * the type of redirections
 * and the name of the file
 * variable to check if the entred 
 * variables will be expended or not : 
 */
typedef struct s_red
{
	t_enum			type;
	char			*file;
	int				dlmtr;
	struct s_red	*next;
}t_red;

/**
 * @brief
 * list to be executed
 * the command 
 * redirections
 */
typedef struct s_execlst
{
	char				**cmd;
	t_red				*red;
	struct s_execlst	*next;
}t_execlst;

typedef struct s_env{
	char			*var;
	char			*val;
	struct s_env	*next;
}	t_env;

//free memory
void		ft_lstclear(t_tok **lst);
void		clear_execlst(t_execlst **lst);
void		free_red(t_red **red);
//tokenizer
t_tok		*lstnew(char *content, t_enum type);
int			add_tkn(t_tok **token, t_tok *new);
t_tok		*tokenizer(char *l);
int			skipword(char *line);
int			skipquotes(char *line);
int			skiptkn(char *line);
//checking syntax
int			check_str(char *l);
int			check_red(t_tok **token);
int			check_pipe(t_tok **token);
int			check_syntax(t_tok *token);
int			exist_pipe(t_tok *token);
int			help_pipe(t_tok **token);
//prepare list for execution
int			add_tknex(t_execlst **token, t_execlst **new);
t_execlst	*get_execlst(t_tok *tkns);
t_execlst	*getred(t_execlst *e, t_tok *tok);
//char		*exec_hrdc(t_red *red);
t_red		*getredlst(t_red *red, t_tok *tok);
t_enum		get_redtype(char *val);
t_execlst	*getcmd(t_execlst *e, char *val);
t_execlst	*init_execlst(void);
//--------------------
void		desplay_shell(t_tok *tokens, t_execlst *el, char **data);
char		*exec_hrdc(t_red *red);
t_env		*init_env(char **env);
void		ft_lstadd_back(t_env **alst, t_env *new);
void		ft_its_builtins(t_execlst *data, t_env *env);
//--------builtins------------
char		*creat_tmp_file(char *file);
void		ft_built_pwd(char *str);
void		ft_built_env(t_env *data);
void		ft_built_cd(char **str, t_env *env);
void		ft_built_echo(char **str);
char		*find_env(char *path, t_env *data);
int			ft_check_newline(char *str);
void		ft_built_exit(char **str);
int			ft_add_variable(char *cmd, t_env *env);
int			is_valide(char *cmd, int i);
void		sort_and_print(char **tab, t_env *env);
void		ft_print_tab(char **tab);
void		ft_add_to_env(char *var, char *val, t_env *env, bool plus);
void		ft_built_unset(char **str, t_env *data);
void		ft_built_export(char **cmd, t_env *env);
int			ft_lstsize(t_env *lst);
#endif