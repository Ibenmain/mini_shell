/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:54:39 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 17:59:50 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

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

int	ft_lstsize(void)
{
	t_env	*tmp;
	int		size;

	size = 0;
	tmp = g_data.g_envlst;
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
	new = (char *)ft_malloc((size_s1 + size_s2) + 2 * \
		sizeof(char), add_garbage_out);
	while (++i < size_s1)
		new[i] = s1[i];
	if (size_s2 != 1)
		new[i++] = '=';
	while (j <= size_s2 + 1)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		new = ft_malloc(1, add_garbage_in);
	else
	{
		if (len > str_len)
			len = str_len;
		new = (char *)ft_malloc((len + 1) * sizeof(char), add_garbage_in);
		while (i < len)
			new[i++] = s[start++];
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr_out(char *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		new = ft_malloc(1, add_garbage_out);
	else
	{
		if (len > str_len)
			len = str_len;
		new = (char *)ft_malloc((len + 1) * sizeof(char), add_garbage_out);
		while (i < len)
			new[i++] = s[start++];
	}
	new[i] = '\0';
	return (new);
}
