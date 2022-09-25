/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:20:59 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/24 20:18:52 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	ft_built_env(t_env *data)
{
	t_env	*env;

	env = data;
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
