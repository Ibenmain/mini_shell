/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:45:32 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/24 17:31:49 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

char	*find_env(char *path)
{
	t_env	*env;

	env = g_data.g_envlst;
	if (path)
	{
		while (env)
		{
			if (!ft_strcmp(path, env->var))
				return (env->val);
			env = env->next;
		}
	}
	return (NULL);
}
