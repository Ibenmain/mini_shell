/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:52:12 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 00:06:25 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

char	*ft_get_pwd(void)
{
	t_env	*env;

	env = g_data.g_envlst;
	if (!env)
		return (NULL);
	while (env)
	{
		if (!ft_strcmp(env->var, "PWD"))
			return (env->val);
		env = env->next;
	}
	return (NULL);
}

void	ft_built_pwd(char *str)
{
	char	s[1024];

	if (*str)
	{
		if (getcwd(s, 1024))
			ft_putendl_fd(s, 1);
		else if (ft_get_pwd())
			ft_putendl_fd(ft_get_pwd(), 1);
		else
			ft_putendl_fd(getenv("PWD"), 1);
	}
}
