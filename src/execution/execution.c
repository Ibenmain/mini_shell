/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:03:22 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/25 21:51:23 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

// struct stat		sfile;
// if (stat(word, &sfile) == -1)
// 	{
// 		printf("Error Occurred\n");
// 		exit(1);
// 	}
// 	if ((sfile.st_mode & S_IFDIR))
// 	{
// 		if (access(word, F_OK) == 0)
// 			return (word);
// 	}

// char	*ft_spare_path(char *word)
// {
// 	char	**tab;
// 	int		i;

// 	i = -1;
// 	tab = ft_split(PATH, ':');
// 	while (tab[++i])
// 	{
// 		tab[i] = ft_add_slache(tab[i], '/');
// 		tab[i] = concat(tab[i], word);
// 		if (access(tab[i], F_OK) == 0)
// 			return (tab[i]);
// 	}
// 	return (NULL);
// }

char	*ft_get_path_of_cmd(char *word)
{
	char			*path;
	char			**tab;
	int				i;

	i = -1;
	if (!word || !g_data.g_envlst)
		return (NULL);
	if (access(word, X_OK) == 0)
		return (word);
	path = find_env("PATH");
	if (!path)
		return (NULL);
	tab = ft_split(path, ':');
	while (tab[++i])
	{
		tab[i] = ft_add_slache(tab[i], '/');
		tab[i] = concat(tab[i], word);
		if (access(tab[i], X_OK) == 0)
			return (tab[i]);
	}
	return (NULL);
}

void	exec_other_cmd(t_execlst *data, int fd[])
{
	char	**tmp_cmd;
	char	**env_tab;
	char	*path;

	if (!data->cmd || !data->cmd[0])
		return ;
	tmp_cmd = data->cmd;
	env_tab = ft_copy_env();
	if (data->next)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
	}
	if (!ft_its_builtins(data) || !redirection(data->red))
		return ;
	path = ft_get_path_of_cmd(tmp_cmd[0]);
	// if (!path)		TODO
	// 	path = ft_spare_path(tmp_cmd[0]);
	if (execve(path, tmp_cmd, env_tab) == -1)
	{
		printf("Minishell: %s: command not found\n", tmp_cmd[0]);
		exit (1);
	}
}

void	ft_cmd_to_exec(t_execlst *el)
{
	int			id;
	int			fd[2];

	while (el)
	{
		if (el->next)
			pipe(fd);
		id = fork();
		if (id < 0)
			return (perror("fork"));
		if (id == 0)
			exec_other_cmd(el, fd);
		if (el->next)
		{
			dup2(fd[0], 0);
			close(fd[0]);
			close(fd[1]);
		}
		else
			close(0);
		el = el->next;
	}
}

int	check_access(t_execlst *el)
{
	if (el->cmd && el->cmd[0][0] == '.' && el->cmd[0][1] == '/')
	{
		if (access(el->cmd[0], X_OK) != 0)
		{
			printf("Minishell: %s: Permission denied\n", el->cmd[0]);
			return (1);
		}
	}
	return (0);
}

void	ft_executer_cmd(t_execlst *el)
{
	int			input;
	int			status;

	input = dup(0);
	if (check_access(el))
		return ;
	if (el && !el->next && !ft_its_builtins(el))
		return ;
	ft_cmd_to_exec(el);
	while (el)
	{
		wait(&status);
		el = el->next;
	}
	dup2(input, 0);
}
