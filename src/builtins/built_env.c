/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:20:59 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/25 21:40:27 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	ft_built_env()
{
	t_env	*env;

	env = g_data.g_envlst;
	while (env)
	{
		if (env->var && env->val)
		{
			ft_putstr_fd(env->var, 1);
			ft_putchar_fd(CHR_EQL, 1);
			ft_putendl_fd(env->val, 1);
		}
		env = env->next;
	}
}
