/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_built_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:06:48 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 00:09:06 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	ft_print_tab(void)
{
	t_env	*data;

	data = g_data.g_envlst;
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

void	sort_and_print(void)
{
	t_env	*tmp;
	t_env	*next;

	if (!g_data.g_envlst)
		return ;
	tmp = g_data.g_envlst;
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
	ft_print_tab();
}
