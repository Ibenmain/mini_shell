/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:18:39 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 18:02:14 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

char	*ft_val(char *data)
{
	int		len;
	char	*str;

	len = ft_index_key(data);
	str = ft_substr_out(data, len + 1, ft_strlen(data) - len);
	if (!str)
		return (NULL);
	return (str);
}

t_env	*ft_creat_node(char *data)
{
	t_env	*env;
	int		shell_lvl;

	env = ft_malloc(sizeof(t_env), add_garbage_out);
	env->var = ft_key(data);
	if (!env->var)
		return (NULL);
	env->val = ft_val(data);
	if (!env->val)
		return (NULL);
	if (!ft_strcmp(env->var, STR_SHLVL))
	{
		shell_lvl = ft_atoi(env->val);
		if (g_data.first > 0)
			shell_lvl++;
		env->val = ft_itoa_out(shell_lvl);
		g_data.first++;
	}
	env->next = NULL;
	return (env);
}
