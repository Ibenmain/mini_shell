/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:04:43 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 17:02:27 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

char	*ft_get_path_of_cmd(char *word)
{
	char	*path;
	char	**tab;
	int		i;

	i = -1;
	if (!word || !*word || !g_data.g_envlst)
		return (NULL);
	path = find_env("PATH");
	tab = ft_split(path, ':');
	if (!tab || !*tab)
		return (NULL);
	while (tab[++i])
	{
		tab[i] = ft_add_slache(tab[i], '/');
		tab[i] = concat(tab[i], word);
		if (access(tab[i], X_OK) == 0)
			return (tab[i]);
	}
	return (NULL);
}

void	ft_dup_one(t_execlst *el, int fd[])
{
	if (el->next)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
	}
}

void	ft_execve_cmd(char *path, char **tmp_cmd, char **env_tab)
{
	if (execve(path, tmp_cmd, env_tab) == -1)
	{
		if (access(path, F_OK) != 1)
		{
			if (errno == EACCES)
			{
				error_msg("Minishell: ", tmp_cmd[0], ": Permission denied");
				g_data.exit_status = 126;
			}
			else if (errno == EFAULT)
			{
				error_msg("Minishell: ", tmp_cmd[0], ": command not found");
				g_data.exit_status = 127;
			}
			else if (errno == ENOENT)
			{
				error_msg("Minishell: ", tmp_cmd[0], \
					": No such file or directory");
				g_data.exit_status = 127;
			}
		}
		exit(g_data.exit_status);
	}
}

void	exec_other_cmd(t_execlst *data, int fd[])
{
	char	**tmp_cmd;
	char	**env_tab;
	char	*path;

	tmp_cmd = data->cmd;
	env_tab = ft_copy_env();
	ft_dup_one(data, fd);
	if (!ft_its_builtins(data) || !redirection(data->red))
		exit (1);
	if (!tmp_cmd || !tmp_cmd[0])
		exit(1);
	path = tmp_cmd[0];
	if (!((tmp_cmd[0][0] == '.' && tmp_cmd[0][1] == '/') \
		|| (tmp_cmd[0][0] == '/')))
		path = ft_get_path_of_cmd(tmp_cmd[0]);
	ft_execve_cmd(path, tmp_cmd, env_tab);
}
