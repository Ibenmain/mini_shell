/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:10:03 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 04:07:01 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	get_c(void)
{
	return (0);
}

void	signals(void)
{
	rl_event_hook = get_c;
	signal(SIGINT, handel_sig_hr);
	signal(SIGQUIT, SIG_IGN);
	rl_catch_signals = 0;
}

int	exec_hrdc(char *buffer, char *file, int fd, int del)
{
	buffer = readline("> ");
	if (!buffer)
		return (0);
	if (g_data.exec == -1)
		return (-1);
	if (!ft_strcmp(file, buffer))
		return (free(buffer), 0);
	put_in_fd(buffer, fd, del);
	free(buffer);
	return (1);
}

int	expand_red(t_enum type, char **file, int delmtr)
{
	int		pi[2];
	int		a;

	if (pipe(pi) == -1)
		return (-1);
	signals();
	if (type == HEREDC)
	{
		*file = expand_hrdc(0, 0, NULL, *file);
		while (1)
		{
			a = exec_hrdc(NULL, *file, pi[1], delmtr);
			if (a == 0)
				break ;
			else if (a == -1)
				return (0);
		}
		return (close(pi[1]), pi[0]);
	}
	else
		return (ft_open(type, file));
}

t_execlst	*expand_list(t_execlst *el)
{
	t_execlst	*tmp;
	int			i;
	t_red		*t;

	tmp = el;
	while (tmp)
	{
		i = -1;
		while (tmp->cmd && tmp->cmd[++i])
		{
			tmp->cmd[i] = _expander(tmp->cmd[i], 0);
			if (!tmp->cmd[i])
				return (NULL);
		}
		t = tmp->red;
		while (t)
		{
			t->fd = expand_red(t->type, &t->file, t->dlmtr);
			t = t->next;
		}
		tmp = tmp->next;
	}
	return (el);
}
