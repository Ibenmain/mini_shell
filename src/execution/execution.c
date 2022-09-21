/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:03:22 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/21 15:16:07 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

char	*ft_add_slache(char *cmd, char c)
{
	char	*tmp;
	int		len;

	if (!cmd)
	{
		tmp = malloc(sizeof(char *) * 2);
		tmp[0] = c;
		tmp[1] = '\0';
		return (tmp);
	}
	len = ft_strlen(cmd);
	tmp = malloc(sizeof(char *) * len + 2);
	ft_strlcpy(tmp, cmd, len + 1);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	return (tmp);
}

char	*get_path(char *cmd, t_env *env)
{
	char	*path;
	char	**tab;
	char	*retn;
	int		i;

	i = -1;
	retn = NULL;
	if (!cmd || !*cmd || !env)
		return (NULL);
	path = find_env("PATH", env);
	tab = ft_split(path, ':');
	while (tab[++i])
	{
		tab[i] = ft_add_slache(tab[i], '/');
		tab[i] = concat(tab[i], cmd);
		if (!retn)
			retn = tab[i];
	}
	return (retn);
}

char	**ft_copy_env(t_env *env)
{
	char	**tab;
	t_env	*tmp;
	int		i;
	int		len;

	i = -1;
	tmp = env;
	len = ft_lstsize(env);
	tab = (char **)malloc(sizeof(char *) * len + 1);
	if (!tab)
		return (NULL);
	while (tmp)
	{
		tab[++i] = ft_strjoin(tmp->var, tmp->val);
		tmp = tmp->next;
	}
	tab[++i] = NULL;
	return (tab);
}

void	exec_other_cmd(t_execlst *data, t_env *env)
{
	char	**tmp_cmd;
	char	**env_tab;
	char	*path;
	char	**tab;
	int		i;

	i = -1;
	tmp_cmd = data->cmd;
	env_tab = ft_copy_env(env);
	if (!tmp_cmd[0] || !*tmp_cmd[0] || !env)
		return ;
	path = find_env("PATH", env);
	tab = ft_split(path, ':');
	while (tab[++i])
	{
		tab[i] = ft_add_slache(tab[i], '/');
		tab[i] = concat(tab[i], tmp_cmd[0]);
		execve(tab[i], tmp_cmd, env_tab);
	}
	printf("Minishell: %s: command not found\n", tmp_cmd[0]);
	exit (1);
}

void	ft_executer_cmd(t_execlst *el, t_env *env)
{
	t_env		*tmp_env;
	t_execlst	*tmp_el;
	int			id;

	tmp_env = env;
	tmp_el = el;
	if (!ft_its_builtins(tmp_el, tmp_env))
		return ;
	while (tmp_el)
	{
		id = fork();
		if (id < 0)
			return (perror("fork"));
		if (id == 0)
		{
			exec_other_cmd(tmp_el, tmp_env);
		}
		else
			wait(0);
		tmp_el = tmp_el->next;
	}
}