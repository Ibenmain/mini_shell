/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_built_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:06:48 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/19 19:07:01 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

void	ft_print_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		printf("declare -x ");
		while (tab[i][j])
		{
			if (tab[i][j - 1] == '=')
				printf("\"");
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\"");
		printf("\n");
		i++;
	}
}

void	sort_and_print(char **tab, t_env *env)
{
	int		len;
	char	*tmp;
	int		i;
	int		j;

	len = ft_lstsize(env);
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (i < len - j - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
	ft_print_tab(tab);
}
