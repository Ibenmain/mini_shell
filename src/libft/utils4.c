/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:54:39 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/24 19:17:48 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

void	add_grb(void **content)
{
	t_grb_clltr	*tmp;

	if (!g_data.g_grb)
	{
		g_data.g_grb = malloc(sizeof(t_grb_clltr));
		g_data.g_grb->value = *content;
		g_data.g_grb->next = NULL;
	}
	else
	{
		tmp = g_data.g_grb;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_grb_clltr));
		tmp->next->value = content;
		tmp->next->next = NULL;
	}
}

void	ft_lstadd_back(t_env **alst, t_env *new)
{
	t_env	*ptr;

	if (!new)
		return ;
	if (alst)
	{
		if (*alst == NULL)
		{
			*alst = new;
			new = NULL;
		}
		else
		{
			ptr = *alst;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new;
		}
	}
}

int	ft_lstsize(t_env *lst)
{
	t_env	*tmp;
	int		size;

	size = 0;
	tmp = lst;
	if (!tmp)
		return (0);
	else
	{
		while (tmp != NULL)
		{
			size++;
			tmp = tmp->next;
		}
	}
	return (size);
}

char	*join_add_eq(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size_s1;
	size_t	size_s2;
	char	*new;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2) + 1;
	new = (char *)malloc((size_s1 + size_s2) + 2 * sizeof(char));
	if (!new)
		return (NULL);
	while (++i < size_s1)
		new[i] = s1[i];
	if (size_s2 != 1)
		new[i++] = '=';
	while (j <= size_s2 + 1)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
