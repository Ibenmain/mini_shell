/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:04:43 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/27 12:10:58 by ibenmain         ###   ########.fr       */
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
		exit (0);
	while (tab[++i])
	{
		tab[i] = ft_add_slache(tab[i], '/');
		tab[i] = concat(tab[i], word);
		if (access(tab[i], X_OK) == 0)
			return (tab[i]);
	}
	return (NULL);
}

// int	check_access(t_execlst *el)
// {
// 	if (el->cmd && el->cmd[0][0] == '.' && el->cmd[0][1] == '/')
// 	{
// 		if (access(el->cmd[0], X_OK) != 0)
// 		{
// 			error_msg("Minishell: ", el->cmd[0], ": No such file or directory");
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

void	ft_dup_one(t_execlst *el, int fd[])
{
	if (el->next)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
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
	if (execve(path, tmp_cmd, env_tab) == -1)
	{
		error_msg("Minishell: ", tmp_cmd[0], ": command not found");
		exit(1);
	}
}
