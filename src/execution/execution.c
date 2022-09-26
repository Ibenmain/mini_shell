/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:03:22 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/26 19:58:46 by ibenmain         ###   ########.fr       */
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
	if (access(word, X_OK) == 0)
		return (word);
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

int	check_access(t_execlst *el)
{
	if (el->cmd && el->cmd[0][0] == '.' && el->cmd[0][1] == '/')
	{
		if (access(el->cmd[0], X_OK) != 0)
		{
			error_msg("Minishell: ", el->cmd[0], ": No such file or directory");
			return (1);
		}
	}
	return (0);
}

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
	if (check_access(data))
		exit(1);
	ft_dup_one(data, fd);
	if (!ft_its_builtins(data) || !redirection(data->red))
		exit (1);
	if (!tmp_cmd || !tmp_cmd[0])
		exit(0);
	path = ft_get_path_of_cmd(tmp_cmd[0]);
	if (execve(path, tmp_cmd, env_tab) == -1)
	{
		error_msg("Minishell: ", tmp_cmd[0], ": command not found");
		exit(1);
	}
}

void	ft_run_command(t_execlst *el, int fd[])
{
	exec_other_cmd(el, fd);
	perror(el->cmd[0]);
	exit(1);
}

void	ft_pipe(t_execlst *el, int fd[])
{
	if (el->next)
	{
		if (pipe(fd) == -1)
		{
			perror("pipe");
			exit(1);
		}
	}
}

void	ft_dup_zero(t_execlst *el, int fd[])
{
	if (el->next)
	{
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
	}
	else
		close(0);
}

void	ft_cmd_to_exec(t_execlst *el)
{
	int	id;
	int	fd[2];

	while (el)
	{
		ft_pipe(el, fd);
		id = fork();
		if (id < 0)
			return (perror("fork"));
		if (id == 0)
			ft_run_command(el, fd);
		ft_dup_zero(el, fd);
		el = el->next;
	}
}


void	ft_executer_cmd(t_execlst *el)
{
	int	input;
	int	status;

	input = dup(0);
	// if (check_access(el))
	// 	return ;
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
