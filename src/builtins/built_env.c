/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:20:59 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 00:04:41 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	ft_built_env(void)
{
	t_env	*env;

	env = g_data.g_envlst;
	if (!env)
		return ;
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
