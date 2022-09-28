/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   its_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:03:01 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/28 15:29:42 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	ft_not_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "env") || \
		!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "echo") || \
		!ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset") || \
		!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

void	ft_exec_bult(t_execlst *data)
{
	if (!ft_strcmp(data->cmd[0], "pwd"))
		ft_built_pwd(data->cmd[0]);
	else if (!ft_strcmp(data->cmd[0], "env"))
		ft_built_env();
	else if (!ft_strcmp(data->cmd[0], "cd"))
		ft_built_cd(data->cmd);
	else if (!ft_strcmp(data->cmd[0], "echo"))
		ft_built_echo(data->cmd);
	else if (!ft_strcmp(data->cmd[0], "export"))
		ft_built_export(data->cmd);
	else if (!ft_strcmp(data->cmd[0], "unset"))
		ft_built_unset(data->cmd);
	else if (!ft_strcmp(data->cmd[0], "exit"))
		ft_built_exit(data->cmd);
}

int	ft_its_builtins(t_execlst *data)
{
	int	fd[2];

	if (!data || !data->cmd || !ft_not_builtin(data->cmd[0]))
		return (1);
	fd[0] = dup(0);
	fd[1] = dup(1);
	if (redirection(data->red) == 0)
		;
	ft_exec_bult(data);
	dup2(fd[0], 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	g_data.exit_status = 0;
	return (0);
}
