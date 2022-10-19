/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:03:22 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 18:36:37 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

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

void	handler(int sig)
{
	if (sig == SIGQUIT)
		ft_putendl_fd("Quit: 3", 1);
}

void	ft_cmd_to_exec(t_execlst *el)
{
	int	id;
	int	fd[2];

	g_data.id_cat = 1;
	while (el)
	{
		ft_pipe(el, fd);
		id = fork();
		if (id < 0)
			return (perror("fork"));
		if (id == 0)
		{
			signal(SIGQUIT, SIG_DFL);
			signal(SIGINT, SIG_DFL);
			exec_other_cmd(el, fd);
		}
		ft_dup_zero(el, fd);
		el = el->next;
	}
}

void	ft_executer_cmd(t_execlst *el)
{
	int	input;
	int	status;

	input = dup(0);
	if (el && !el->next && !ft_its_builtins(el))
		return ;
	ft_cmd_to_exec(el);
	while (1)
	{
		if (wait(&status) == -1)
			break ;
	}
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
			write(1, "\n", 1);
		if (WTERMSIG(status) == SIGQUIT)
			write(1, "Quit: 3\n", 8);
		g_data.exit_status = 128 + WTERMSIG(status);
	}
	else if (WIFEXITED(status))
		g_data.exit_status = WEXITSTATUS(status);
	dup2(input, 0);
	close (input);
}
