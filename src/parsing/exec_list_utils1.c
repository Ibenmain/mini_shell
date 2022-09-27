/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_list_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:04:31 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/27 12:41:34 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

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
	if (!new)
		return (NULL);
	new[i + 1] = NULL;
	new[i] = val;//expander(NULL, val, 0);
	if (!new[i])
		return (NULL);
	while (--i >= 0 && e->cmd[i])
		new[i] = e->cmd[i];//expander(NULL, e->cmd[i], 0);
	return (e->cmd = new, e);
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

t_red	*new_red(t_tok *tok)
{
	t_red	*head;

	head = malloc(sizeof(t_red));
	if (!head)
		return (NULL);
	head->type = get_redtype(tok->value);
	head->file = tok->next->value;
	head->next = NULL;
	return (head);
}

t_red	*getredlst(t_red *red, t_tok *tok)
{
	t_red	*t;

	if (!red)
	{
		red = new_red(tok);
		if (!red)
			return (NULL);
	}
	else
	{
		t = red;
		while (t->next)
			t = t->next;
		t->next = new_red(tok);
		if (!t->next)
			return (NULL);
	}
	return (red);
}
