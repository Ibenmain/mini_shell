/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:49:46 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/03 15:16:44 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

void	ft_print_error(char *str)
{
	printf("minishell: cd: %s not set\n", str);
}

int	ft_get_path(char *cmd, t_env *env)
{
	char	*path;
	t_env	*tmp;
	int		i;

	tmp = env;
	if (!ft_strcmp(cmd, "-"))
	{
		path = find_env("OLDPWD", tmp);
		if (!path)
			return (ft_print_error("OLDPWD"), 0);
		printf("%s\n", path);
		i = chdir(path);
	}
	else
		i = chdir(cmd);
	return (i);
}

void	ft_built_cd(char **str, t_env *env)
{
	int		i;
	char	*path;

	if (!str[1])
	{
		path = find_env("HOME", env);
		if (!path)
			ft_print_error("HOME");
		i = chdir(path);
	}
	else
		i = ft_get_path(str[1], env);
	if (i < 0)
		perror("cd");
}
