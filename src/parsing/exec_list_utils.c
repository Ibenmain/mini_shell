/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:04:31 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/08/27 01:10:21 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
void	free_arr2d(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}



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
		new[i] = e->cmd[i];
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

char	*exec_hrdc(t_red *red)
{
	return (red->file);
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
			t->file = exec_hrdc(t);
		t = t->next;
	}
	return (e);
}

void	clear_exec_lst(t_execlst *lst)
{
	t_execlst	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst->next;
		free_arr2d(lst->cmd);
		
	}
}

t_execlst	*get_execlst(t_tok *tkns)
{
	t_tok		*tmp;
	t_execlst	*exec;
	t_execlst	*hpex;
	exec = NULL;
	hpex = NULL;
	tmp = tkns;
	while (tmp)
	{
		if (tmp->type == WORD || tmp->type == D_QTE || tmp->type == S_QTE)
		{
			hpex = getcmd(hpex, tmp->value);
		}
		else if (tmp->type == RED)
		{
			hpex = getred(hpex, tmp);
			tmp = tmp->next;
		}
		if (!hpex)
			return (NULL);
		if (tmp->type == PIPE || !tmp->next)
			if (add_tknex(&exec, &hpex))
				return (NULL);
		tmp = tmp->next;
	}
	return (exec);
}



void	free_red(t_red **red)
{
	t_red	*tmp;

	if (red)
	{
		while (*red)
		{
			tmp = (*red)->next;
			//free((*red)->file);
			free(*red);
			*red = tmp;
		}
	}	
}

void	clear_execlst(t_execlst **lst)
{
	t_execlst	*tmp;
	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst)->cmd);
			free_red(&(*lst)->red);
			free(*lst);
			*lst = tmp;
		}
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

