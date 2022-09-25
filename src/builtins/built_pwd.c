/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:52:12 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/24 17:28:13 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

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
