/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:41:02 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/03 14:09:11 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

void	ft_delete_element(char *cmd, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (!ft_strcmp(cmd, tmp->var))
	{
		tmp = env->next;
		return ;
	}
	while (tmp)
	{
		if (tmp->next && !ft_strcmp(cmd, tmp->next->var))
		{
			tmp->next = tmp->next->next;
			// if (tmp->next->next != NULL)
			// 	free(tmp->next->next);
		}
		tmp = tmp->next;
	}
}

void	ft_built_unset(char **str, t_env *data)
{
	t_env	*tmp;
	int		i;

	tmp = data;
	i = 0;
	if (!str || !*str)
		return ;
	if (str[1])
	{
		while (str[++i])
			ft_delete_element(str[i], tmp);
	}
}
