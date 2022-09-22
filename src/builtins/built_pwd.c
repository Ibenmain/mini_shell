/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:52:12 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/22 19:18:56 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

char	*ft_get_pwd(t_env *env)
{
	while (env)
	{
		if (!ft_strcmp(env->var, "PWD"))
			return (env->val);
		env = env->next;
	}
	return (NULL);
}

void	ft_built_pwd(char *str, t_env *env)
{
	char	s[1024];

	if (*str)
	{
		if (getcwd(s, 1024))
			ft_putendl_fd(s, 1);
		else if (ft_get_pwd(env))
			ft_putendl_fd(ft_get_pwd(env), 1);
		else
			ft_putendl_fd(getenv("PWD"), 1);
	}
}
