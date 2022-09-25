/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_built_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:06:48 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/24 17:28:23 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int check_egale(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		return (1);
		i++;
	}
	return (0);
}

void ft_print_tab(t_env *env)
{
	t_env *data;

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

void	ft_swap(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void	sort_and_print(t_env *env)
{
	t_env	*tmp;
	t_env	*next;

	if (!env)
		return ;
	tmp = env;
	while (tmp && tmp->next)
	{
		next = tmp->next;
		while (next)
		{
			if (ft_strcmp(tmp->var, next->var) > 0)
			{
				ft_swap(&tmp->var, &next->var);
				ft_swap(&tmp->val, &next->val);
			}
			next = next->next;
		}
		tmp = tmp->next;
	}
	ft_print_tab(env);
}
