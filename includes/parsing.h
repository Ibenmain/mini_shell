/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 07:38:32 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/24 13:52:19 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H

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

/**
 * @brief list for environment variables
 * with their sizes
 */
typedef struct s_env
{
	char			*var;
	char			*val;
	int				sz_var;
	int				sz_val;
	struct s_env	*next;
}t_env;

typedef struct s_grb_collector
{
	void					*value;
	struct s_grb_collector	*next;
}t_grb_clltr;

typedef struct s_data
{
	t_env			*g_envlst;
	t_grb_clltr		*g_grb;
	int				exit_status;
	struct s_data	*next;
}t_data;

t_data	g_data;

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
// char		*exec_hrdc(t_red *red);
t_red		*getredlst(t_red *red, t_tok *tok);
t_enum		get_redtype(char *val);
t_execlst	*getcmd(t_execlst *e, char *val);
t_execlst	*init_execlst(void);

#endif