/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_built_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:06:48 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/21 11:28:36 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

int	check_egale(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		return (1);
		i++;
	}
	return (0);
}

void	ft_print_tab(t_env *env)
{
	t_env	*data;

	data = env;
	while (data)
	{
		printf("declare -x %s", data->var);
		if (data->val)
			printf("=\"%s\"", data->val);
		printf("\n");
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
