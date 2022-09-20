/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_list_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:04:31 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/08/29 14:08:05 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

t_execlst	*init_execlst(void)
{
	t_execlst	*e;

	e = malloc(sizeof(t_execlst));
	if (!e)
		return (NULL);
	e->cmd = NULL;
	e->red = NULL;
	e->next = NULL;
	return (e);
}

t_execlst	*getcmd(t_execlst *e, char *val)
{
	int		i;
	char	**new;

	if (!e)
		e = init_execlst();
	if (!e)
		return (NULL);
	i = 0;
	while (e->cmd && e->cmd[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	new[i + 1] = NULL;
	new[i] = val;
	while (--i >= 0 && e->cmd[i])
	{
		new[i] = e->cmd[i]/*expender(e->cmd[i])*/;//TODO add expender
		e->cmd[i] = NULL;
	}
	return (free(e->cmd), e->cmd = new, e);
}

t_enum	get_redtype(char *val)
{
	if (!ft_strcmp(val, STR_OUTR))
		return (REDOUT);
	else if (!ft_strcmp(val, STR_APND))
		return (APPND);
	else if (!ft_strcmp(val, STR_INR))
		return (REDIN);
	else if (!ft_strcmp(val, STR_HRDC))
		return (HEREDC);
	return (NON);
}

t_red	*getredlst(t_red *red, t_tok *tok)
{
	t_red	*t;

	if (!red)
	{
		red = malloc(sizeof(t_red));
		if (!red)
			return (NULL);
		red->type = get_redtype(tok->value);
		red->file = tok->next->value;
		red->next = NULL;
	}
	else
	{
		t = red;
		while (t->next)
			t = t->next;
		t->next = malloc(sizeof(t_red));
		if (!t->next)
			return (NULL);
		t->next->type = get_redtype(tok->value);
		t->next->file = tok->next->value;
		t->next->next = NULL;
	}
	return (red);
}

t_execlst	*getred(t_execlst *e, t_tok *tok)
{
	t_red	*t;

	if (!e)
		e = init_execlst();
	if (!e)
		return (NULL);
	e->red = getredlst(e->red, tok);
	t = e->red;
	while (t)
	{
		if (t->type == HEREDC)
		{
			if (ft_strchr(t->file, CHR_D_QT) || ft_strchr(t->file, CHR_S_QT))
				t->dlmtr = 0;
			else
				t->dlmtr = 1;
		}
		exec_hrdc(e->red);
		t = t->next;
	}
	return (e);
}
