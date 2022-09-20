/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   its_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:03:01 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/03 14:37:35 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

void	ft_its_builtins(t_execlst *data, t_env *env)
{
	if (!data)
		return ;
	if (!ft_strcmp(data->cmd[0], "pwd"))
		ft_built_pwd(data->cmd[0]);
	else if (!ft_strcmp(data->cmd[0], "env"))
		ft_built_env(env);
	else if (!ft_strcmp(data->cmd[0], "cd"))
		ft_built_cd(data->cmd, env);
	else if (!ft_strcmp(data->cmd[0], "echo"))
		ft_built_echo(data->cmd);
	else if (!ft_strcmp(data->cmd[0], "export"))
		ft_built_export(data->cmd, env);
	else if (!ft_strcmp(data->cmd[0], "unset"))
		ft_built_unset(data->cmd, env);
	else if (!ft_strcmp(data->cmd[0], "exit"))
		ft_built_exit(data->cmd);
}
