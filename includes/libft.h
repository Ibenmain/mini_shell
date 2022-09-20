/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:02:31 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/08/25 17:06:18 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include<stdio.h>
# include<stdlib.h>
# include<string.h>

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

typedef struct s_tok
{
	char			*value;
	t_enum			type;
	struct s_tok	*next;
}t_tok;

typedef struct s_red
{
	t_enum			type;
	char			*file;
	struct s_red	*next;
}t_red;

typedef struct s_execlst
{
	char				**cmd;
	t_red				*red;
	struct s_execlst	*next;
}t_execlst;

void	ft_lstclear(t_tok **lst);
t_tok	*lstnew(char *content, t_enum type);
int		add_tkn(t_tok **token, t_tok *new);
int		add_tknex(t_execlst **token, t_execlst **new);
char	*getval(char *s, int start, int len);
int		ft_strlen(char *str);
int		ft_strchr(char *s, char c);
char	*ft_strtrim(char *s1, char *set);
int		str_error(char *str);
t_tok	*revlst(t_tok *list);
int		ft_strcmp(char *s1, char *s2);
#endif