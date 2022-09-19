/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:45:32 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/03 00:12:21 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

char	*find_env(char *path, t_env *data)
{
	t_env	*env;

	env = data;
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
