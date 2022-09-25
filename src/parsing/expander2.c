/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:10:03 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/24 19:37:28 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	sizehrdc(char *file)
{
	int	i;
	int	sz;

	sz = 0;
	i = -1;
	while (file[++i])
	{
		if (file[i] == '\'')
			while (file[++i] && file[i] != '\'')
				sz++;
		else if (file[i] && file[i] == '\"')
			while (file[++i] && file[i] != '\"')
				sz++;
		else
		{
			sz++;
			while (file[++i] && file[i] != '\"' && file[i] != '\'')
				sz++;
			if (!file[i] || file[i] == '\"' || file[i] == '\'')
				i--;
		}
	}
	return (sz);
}

char	*expand_hrdc(int i, int j, char *name_file, char *file)
{
	i = sizehrdc(file);
	name_file = malloc(i + 1);
	if (!name_file)
		return (NULL);
	j = 0;
	i = -1;
	while (file[++i])
	{
		if (file[i] == '\'')
			while (file[++i] && file[i] != '\'')
				name_file[j++] = file[i];
		else if (file[i] == '\"')
			while (file[++i] && file[i] != '\"')
				name_file[j++] = file[i];
		else
		{
			name_file[j++] = file[i];
			while (file[++i] && file[i] != '\'' && file[i] != '\"')
				name_file[j++] = file[i];
			if (!file[i] || file[i] == '\"' || file[i] == '\'')
				i--;
		}
	}
	return (name_file[j] = '\0', name_file);
}

void	test(int i)
{
	(void)i;
	write(1, "\n", 1);
	//rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	close(0);
}

char	*expand_red(t_enum type, char *file, int delmtr)
{
	char	*file_name;
	int		pid;

	if (type == HEREDC)
	{
		file_name = expand_hrdc(0, 0, NULL, file);
		pid = fork();
		if (pid == 0)
		{
			signal(SIGINT,test);
			file_name = exec_hrdc(file_name, delmtr);
		}
		else
			wait(&g_data.exit_status);
	}
	else
		file_name = expander(NULL, file, 0);
	return (file_name);
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
			tmp->cmd[i] = expander(NULL, tmp->cmd[i], 0);
			if (!tmp->cmd[i])
				return (NULL);
		}
		t = tmp->red;
		while (t)
		{
			t->file = expand_red(t->type, t->file, t->dlmtr);
			if (!t->file)
				return (NULL);
			t = t->next;
		}
		tmp = tmp->next;
	}
	return (el);
}