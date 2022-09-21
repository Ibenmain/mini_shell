/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   its_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:03:01 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/21 14:25:03 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

int	ft_its_builtins(t_execlst *data, t_env *env)
{
	if (!data)
		return (1);
	if (!ft_strcmp(data->cmd[0], "pwd"))
		return (ft_built_pwd(data->cmd[0]), 0);
	else if (!ft_strcmp(data->cmd[0], "env"))
		return (ft_built_env(env), 0);
	else if (!ft_strcmp(data->cmd[0], "cd"))
		return (ft_built_cd(data->cmd, env), 0);
	else if (!ft_strcmp(data->cmd[0], "echo"))
		return (ft_built_echo(data->cmd), 0);
	else if (!ft_strcmp(data->cmd[0], "export"))
		return (ft_built_export(data->cmd, env), 0);
	else if (!ft_strcmp(data->cmd[0], "unset"))
		return (ft_built_unset(data->cmd, env), 0);
	else if (!ft_strcmp(data->cmd[0], "exit"))
		return (ft_built_exit(data->cmd), 0);
	return (1);
}
