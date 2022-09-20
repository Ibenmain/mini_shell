/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_built_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:06:48 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/20 16:05:45 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

void	ft_print_tab(t_env *env)
{
	t_env	*data;

	data = env;
	while (data)
	{
		if (!data->val)
		{
			ft_putstr_fd(data->var, 1);
			write(1, "\n", 1);
		}
		else
		{
			ft_putstr_fd(data->var, 1);
			ft_putchar_fd(CHR_EQL, 1);
			ft_putendl_fd(data->val, 1);
		}
		data = data->next;
	}
}

void	sort_and_print(t_env *env)
{
	char	*tp;
	t_env	*tmp;
	t_env	*next;

	tmp = env;
	while (tmp && tmp->next)
	{
		next = tmp->next;
		while (next)
		{
			if (ft_strcmp(tmp->var, next->var) > 0)
			{
				tp = tmp->var;
				tmp->var = next->var;
				next->var = tp;
			}
			next = next->next;
		}
		tmp = tmp->next;
	}
	ft_print_tab(env);
}
