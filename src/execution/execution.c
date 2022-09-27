/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:03:22 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/27 12:36:04 by ibenmain         ###   ########.fr       */
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
		{
			exec_other_cmd(el, fd);
			perror(el->cmd[0]);
			exit(1);
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
	while (el)
	{
		wait(&status);
		el = el->next;
	}
	dup2(input, 0);
}
